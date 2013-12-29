#coding: utf-8;
import numpy as np

fname = "data/sample.in.txt"
#fname = "data/problem.in.txt"

import pyximport
pyximport.install(setup_args={'include_dirs':[np.get_include()]}, inplace=True)
from utils import *

with open(fname, mode='r') as fp:
    N = int(fp.readline())
    W = int(fp.readline())
items = np.loadtxt(fname, dtype=np.int, delimiter=' ', skiprows=2)
items = np.r_[[[0,]*items.shape[1]], items]

knapsack(items, N, W)
