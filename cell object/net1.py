'''
Description: 
version: 
Author: Rundong Wang
Date: 2023-02-17 08:33:58
LastEditors: Please set LastEditors
LastEditTime: 2023-02-17 08:38:12
'''
import torch as t
from torch import nn, functional as F

class config:
    input_layer = ''

class net(nn.Module):
    def __init__(self, config) -> None:
        super(net, self).__init__(config)
        
    