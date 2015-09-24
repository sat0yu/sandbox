# coding: utf-8;
from __future__ import division, print_function, unicode_literals
from future_builtins import *
s = raw_input()
pre = ''
count = 0
res = ''
for x in s:
    if x == pre:
        count += 1
    else:
        res += pre + str(count)
        count = 1
    pre = x
res += pre + str(count)
print(res[1:])
