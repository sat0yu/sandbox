#coding: utf-8;
from __future__ import division, print_function, unicode_literals
from future_builtins import *

class Queue:
    def __init__(self):
        self._que = []

    def size(self):
        return len(self._que)

    def enqueue(self, i):
        self._que.append(i)

    def dequeue(self):
        if not len(self._que) > 0:
            raise IndexError("empty queue.")

        ret = self._que[0]
        self._que = self._que[1:]
        return ret

def naive_bfs(S, T):
    depth = 1
    n = int(len(S) / 2)
    mask = {}
    que = Queue()
    que.enqueue(S)
    que.enqueue(False)
    while que.size() > 0:
        seq = que.dequeue()
        if seq is False:
            depth += 1
            que.enqueue(False)
            continue
        seqs = [ seq[i:i+n]+seq[:i]+seq[i+n:] for i in range(1,n+1) ]
        #print(depth,seqs)
        #raw_input()
        for _S in seqs:
            if _S == T:
                print("HIT:",depth,_S)
                return depth
            if not mask.has_key(_S):
                print(depth,_S)
                que.enqueue(_S)
                mask[_S] = True
            else:
                print("already visited.")

def reverse_bfs(T, P):
    depth = 1
    n = int(len(P) / 2)
    mask = {}
    que = Queue()
    que.enqueue(P)
    que.enqueue(False)
    while que.size() > 0:
        seq = que.dequeue()
        if seq is False:
            depth += 1
            que.enqueue(False)
            continue
        seqs = [ seq[n:n+i]+seq[:n]+seq[n+i:] for i in range(1,n+1) ]
        #print(depth,seqs)
        #raw_input()
        for _P in seqs:
            if _P == T:
                print("HIT:",depth,_P)
                return depth
            if not mask.has_key(_P):
                print(depth,_P)
                que.enqueue(_P)
                mask[_P] = True
            else:
                print("already visited.")

if __name__ == '__main__':
    source = "1234567890"
    target = "0987654321"
    #print( naive_bfs(source, target) )
    print( reverse_bfs(source, target) )
