# -*- coding:utf-8 -*-
import numpy as np
import codecs

import pyximport
pyximport.install(setup_args={'include_dirs':[np.get_include()]}, inplace=True)
from utils import *

fname = 'data/hyakunin.csv'
with codecs.open(fname, mode='r', encoding='shift-jis') as fp:
    # skip first row
    fp.readline()
    # read rest of files
    data = [row.split(u',')[3:5] for row in fp.readlines()]

data.sort()
N, UD, LD = 0, {}, {}
for i in data:
    upper, lower = i[0], i[1]

    j = 1
    while UD.get(upper[:j], None) is not None:
        j += 1
    #print upper[:j], upper
    UD[upper[:j]] = upper
    N += j

    j = 1
    while LD.get(lower[:j], None) is not None:
        j += 1
    #print lower[:j], lower
    LD[lower[:j]] = lower
    N += j

print N
