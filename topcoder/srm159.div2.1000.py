#coding=utf-8
from __future__ import division, print_function, unicode_literals
from future_builtins import *

class ThePriceIsRight:
    def howManyReveals(self, prices):
        N = len(prices)
        dp = [[0 for j in range(N)] for i in range(N)]

        for i in range(N):
            dp[0][i] = 0
            dp[i][0] = 1

        for i in range(1,N):
            for j in range(1,N):
                dp[i][j] = sum([ dp[k][j-1] for k in range(i) if prices[i] > prices[k] ])

        for j in reversed(range(N)):
            counter = sum([ dp[i][j] for i in range(N) ])
            if counter > 0:
                return (j+1, counter)

if __name__ == '__main__':
    ins = ThePriceIsRight()
    if (4,1) != ins.howManyReveals((30,10,20,40,50)): raise ValueError("Wrong Answer.")
    if (10,1) != ins.howManyReveals((1,2,3,4,5,6,7,8,9,10)): raise ValueError("Wrong Answer.")
    if (1,10) != ins.howManyReveals((10,9,8,7,6,5,4,3,2,1)): raise ValueError("Wrong Answer.")
    if (4,2) != ins.howManyReveals((39,88,67,5,69,87,82,64,58,61)): raise ValueError("Wrong Answer.")
    if (5,2) != ins.howManyReveals((29,31,73,70,14,5,6,34,53,30,15,86)): raise ValueError("Wrong Answer.")
