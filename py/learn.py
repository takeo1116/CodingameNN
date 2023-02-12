# coding:utf-8

import torch
import os
import argparse
from torch import nn, optim
from features import Features
from network import PVNetwork, BigModel
from torch.utils.data import TensorDataset, DataLoader

parser = argparse.ArgumentParser(description="棋譜データから教師あり学習を行う")
parser.add_argument("--output_path", type=str, default="./model/SL_output", help="グラフ、モデルをoutputするディレクトリ")
args = parser.parse_args()

# outputするディレクトリを作成
os.makedirs(args.output_path, exist_ok=True)
os.makedirs(os.path.join(args.output_path, "models"), exist_ok=True)

device = "cpu"

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

features = torch.Tensor(features).to(device)
values = torch.Tensor(values).to(device)
turns = torch.LongTensor(turns).to(device)

dataset = TensorDataset(features, values, turns)

dataloader = DataLoader(dataset, 100, shuffle=True)

model = PVNetwork().to(device)
# model = BigModel().to(device)

optimizer = optim.Adagrad(model.parameters(), lr=0.01)
softmax = nn.Softmax(dim=1)
loss_fn_p = nn.CrossEntropyLoss()
loss_fn_v = nn.MSELoss()

torch.set_printoptions(edgeitems=1000)

for epoch in range(100):
    model_path = f"{args.output_path}/models/state_{epoch}.pth"

    for feature_tensor, value_tensor, turns_tensor in dataloader:
        optimizer.zero_grad()
        p_out, v_out = model(feature_tensor)
        p_tensor, v_tensor = torch.split(value_tensor, [81, 1], dim=1)
        loss_p = loss_fn_p(p_out, p_tensor)
        # loss_v = loss_fn_v(v_out, v_tensor)
        # loss = loss_p + loss_v
        loss_p.backward()
        optimizer.step()

        # torch.set_printoptions(sci_mode=False)
        print("---")
        print(f"pv: {softmax(p_out)}")
        print(f"target: {value_tensor}")
        print(f"turns: {turns_tensor}")
        print(f"loss: {loss_p}")

    torch.save(model.state_dict(), model_path)
