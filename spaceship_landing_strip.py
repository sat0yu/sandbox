#coding: utf-8;
from __future__ import division, print_function, unicode_literals
from future_builtins import *

def checkio(landing_map):
    map_H, map_W = len(landing_map), len(landing_map[0])
    area = 0
    for i in range(map_H):
        for j in range(map_H - i):
            x, w = 0, 1
            while x + w <= map_W:
                #print(i,j,x,w,area)
                #raw_input()
                h = i + 1
                if not ( h == sum([ (landing_map[l][x+w-1] == 'G'\
                        or landing_map[l][x+w-1] == 'S')\
                        for l in range(j,j+h) ]) ):
                    x += w
                    w = 1
                else:
                    area = w * h if w * h > area else area
                    w += 1
    return area

#These "asserts" using only for self-checking and not necessary for auto-testing
if __name__ == '__main__':
    assert checkio(['G']) == 1, 'One cell - one variant'
    assert checkio(['GS',
                    'GS']) == 4, 'Four good cells'
    assert checkio(['GT',
                    'GG']) == 2, 'Four cells, but with a tree'
    assert checkio(['GGTGG',
                    'TGGGG',
                    'GSSGT',
                    'GGGGT',
                    'GWGGG',
                    'RGTRT',
                    'RTGWT',
                    'WTWGR']) == 9, 'Classic'
