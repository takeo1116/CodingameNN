# coding:utf-8

import torch
import os
import argparse
from torch import nn, optim
from features import Features
from network import PVNetwork
from torch.utils.data import TensorDataset, DataLoader

parser = argparse.ArgumentParser(description="モデルファイルをC++用に書き出す")
parser.add_argument("--output_path", type=str, default="./model/SL_output/models/state_375.pth", help="モデルファイル")
args = parser.parse_args()

model = PVNetwork()
model.load_state_dict(torch.load(args.output_path))

print(model.get_parameter_string())