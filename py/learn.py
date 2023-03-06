# coding:utf-8

import torch
import os
import argparse
# import matplotlib.pyplot as plt
from torch import nn, optim
from features import Features
from network import PVNetwork
from torch.utils.data import TensorDataset, DataLoader

parser = argparse.ArgumentParser(description="棋譜データから教師あり学習を行う")
parser.add_argument("--output_path", type=str, default="./model/SL_output", help="グラフ、モデルをoutputするディレクトリ")
args = parser.parse_args()

# outputするディレクトリを作成
os.makedirs(args.output_path, exist_ok=True)
os.makedirs(os.path.join(args.output_path, "models"), exist_ok=True)

device = "cuda"

features = []
values = []
turns = []

records_path = "../records/"
dirs = [os.path.join(records_path, dir) for dir in os.listdir(
    records_path) if os.path.isdir(os.path.join(records_path, dir))]
for dir in dirs:
    files = [os.path.join(dir, file) for file in os.listdir(
        dir) if os.path.isfile(os.path.join(dir, file))]
    print(files)
    for path in files:
        with open(path) as f:
            for line in f:
                feature, value, turn = Features.make_features(line)
                features.append(feature)
                values.append(value)
                turns.append(turn)
    print(f"size: {len(features)}")
    break

features = torch.Tensor(features).to(device)
values = torch.Tensor(values).to(device)
turns = torch.LongTensor(turns).to(device)

dataset = TensorDataset(features, values, turns)

train_size = int(0.8 * len(dataset))
test_size = len(dataset) - train_size

print(train_size, test_size)

train_dataset, test_dataset = torch.utils.data.random_split(dataset, [train_size, test_size])

train_dataloader = DataLoader(train_dataset, 1000, shuffle=True)
test_dataloader = DataLoader(test_dataset, 1000, shuffle=True)

model = PVNetwork().to(device)

optimizer = optim.Adagrad(model.parameters(), lr=0.01)
softmax = nn.Softmax(dim=1)
loss_fn_p = nn.CrossEntropyLoss()
loss_fn_v = nn.MSELoss()

for epoch in range(100000):
    model_path = f"{args.output_path}/models/state_{epoch}.pth"
    correct = 0
    loss_sum = 0.0

    model.train()
    for feature_tensor, value_tensor, turns_tensor in train_dataloader:
        optimizer.zero_grad()
        p_out, v_out = model(feature_tensor)
        p_tensor, v_tensor = torch.split(value_tensor, [81, 1], dim=1)
        # print(p_tensor)
        loss_p = loss_fn_p(p_out, p_tensor)
        loss_sum += loss_p.item() * feature_tensor.shape[0]
        # loss_v = loss_fn_v(v_out, v_tensor)
        # loss = loss_p + loss_v
        loss_p.backward()
        optimizer.step()

        _, target = torch.max(value_tensor, 1)
        _, predicted = torch.max(p_out.data, 1)
        # print(f"target: {target}")
        # print(f"predicted: {predicted}")
        correct += predicted.eq(target.data.view_as(predicted)).sum()

        # torch.set_printoptions(sci_mode=False)
        # print("---")
        # print(f"pv: {softmax(p_out)}")
        # print(f"target: {value_tensor}")
        # print(f"turns: {turns_tensor}")
        # print(f"loss: {loss_p}")

    data_num = len(train_dataloader.dataset)
    loss_mean = loss_sum / data_num
    accuracy = correct / data_num

    print(f"train_loss_mean: {loss_mean}")
    print(f"train_accuracy: {accuracy}")

    correct = 0
    loss_sum = 0.0
    model.eval()
    for feature_tensor, value_tensor, turns_tensor in test_dataloader:
        p_out, v_out = model(feature_tensor)
        p_tensor, v_tensor = torch.split(value_tensor, [81, 1], dim=1)
        loss_p = loss_fn_p(p_out, p_tensor)
        loss_sum += loss_p.item() * feature_tensor.shape[0]

        _, target = torch.max(value_tensor, 1)
        _, predicted = torch.max(p_out.data, 1)
        correct += predicted.eq(target.data.view_as(predicted)).sum()
    data_num = len(test_dataloader.dataset)
    loss_mean = loss_sum / data_num
    accuracy = correct / data_num

    print(f"test_loss_mean: {loss_mean}")
    print(f"test_accuracy: {accuracy}")

    torch.save(model.state_dict(), model_path)
