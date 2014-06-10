#coding: utf-8;
import numpy as np

import pyximport
pyximport.install(setup_args={'include_dirs':[np.get_include()]}, inplace=True)
from utils import *

C = np.array([
        [ 0, 7, 12, 8, 11, 7 ],
        [ 3, 0, 10, 7, 13, 2 ],
        [ 4, 8, 0, 9, 12, 3 ],
        [ 6, 6, 9, 0, 10, 7 ],
        [ 7, 7, 11, 10, 0, 5 ],
        [ 9, 7, 8, 9, 10, 0 ],
    ])

min_score = 999
# consider permitation of {2,3,4,5,6} meaning visit point
N=5
for i in range(factorial(N)):
    # generate permitation
    d = numToFactoradic(i, N-1)
    n = factoradicToNum(d)
    p = factoradicToPermitation(range(2,N+2), d)

    # add start/end point
    p = [1,] + p + [1,]

    # search the opt. route
    score = sum([ C[ p[j]-1, p[j+1]-1 ] for j in range(N+1) ])
    if score < min_score:
        min_score, opt = score, p

print min_score
print ' -> '.join([str(i) for i in opt])
