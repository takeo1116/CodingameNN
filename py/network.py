# coding:utf-8

import torch
from torch import nn
import torch.nn.functional as F

class Block(nn.Module):
    def forward(self, x):
        h = self.linear1(x)
        h = self.linear2(h)
        h = self.out(h)
        return h

    def __init__(self):
        super(Block, self).__init__()
        self.linear1 = nn.Linear(in_feature=16, out_feature=16)
        self.linear2 = nn.Linear(in_feature=16, out_feature=16)
        self.out = nn.Linear(in_feature=16, out_feature=5)


class PVNetwork(nn.Module):

    def forward(self, x):
        sliced = [x[:,n:n+1,:] for n in range(192)]
        y = torch.cat(tuple(sliced), dim=2)
        y = y.squeeze()
        z = self.test1(y)
        z = self.test2(z)
        z = self.test3(z)
        return self.sig(z)

    def __init__(self):
        super(PVNetwork, self).__init__()
        self.sig = nn.Sigmoid()
        self.test1 = nn.Linear(in_features=192*16, out_features=1000)
        self.test2 = nn.Linear(in_features=1000, out_features=500)
        self.test3 = nn.Linear(in_features=500, out_features=82)
        # self.block1 = Block()
        # self.block2 = Block()
        # self.block3 = Block()
        # self.block4 = Block()
        # self.block5 = Block()
        # self.block6 = Block()
