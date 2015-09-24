# coding: utf-8;
from __future__ import division, print_function, unicode_literals
from future_builtins import *
strlist = raw_input()
arr = [int(x) for x in strlist.split()]
print(sorted(arr)[1])
