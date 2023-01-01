# coding:utf-8

import torch
import os
from torch import nn, optim
from features import Features
from network import PVNetwork
from torch.utils.data import TensorDataset, DataLoader

device = "cpu"

features = []
values = []

records_path = "../cpp/records/"
dirs = [os.path.join(records_path, dir) for dir in os.listdir(
    records_path) if os.path.isdir(os.path.join(records_path, dir))]
for dir in dirs:
    files = [os.path.join(dir, file) for file in os.listdir(
        dir) if os.path.isfile(os.path.join(dir, file))]
    print(files)
    for path in files:
        with open(path) as f:
            for line in f:
                feature, value = Features.make_features(line)
                features.append(feature)
                values.append(value)

features = torch.Tensor(features).to(device)
values = torch.Tensor(values).to(device)

dataset = TensorDataset(features, values)

dataloader = DataLoader(dataset, 1000, shuffle=True)

model = PVNetwork().to(device)

optimizer = optim.Adagrad(model.parameters(), lr=0.01)
loss_fn = nn.BCELoss()

for feature_tensor, value_tensor in dataloader:
    optimizer.zero_grad()
    pv = model(feature_tensor)
    loss = loss_fn(pv, value_tensor)
    loss.backward()
    optimizer.step()

    torch.set_printoptions(sci_mode=False)
    print("---")
    print(f"pv: {pv}")
    print(f"target: {value_tensor}")
    print(f"loss: {loss}")
