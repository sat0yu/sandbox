#coding: utf-8;
import numpy as np

def fact(n):
    if n <= 1:
        return 1
    else:
        return f(n-1)*n

def perm(*args):
    numerator = fact( sum(args) )
    for a in args:
        numerator /= fact(a)
    return numerator

def make_count():
    dictionary = {}
    def count(head, args):
        elems = args[:]
        for i,e in enumerate(elems):
            if e <= 0:
                del elems[i]

        key = "%r%r" % (head,args)
        if dictionary.has_key(key):
            return dictionary[key]
        else:
            if len(elems) > 0:
                if elems[head] > 1:
                    elems[head] -= 1
                else:
                    del elems[head]
            else:
                return 1

            buf = 1
            for i in range(len(elems)):
                buf += count(i,elems)

            dictionary[key] = buf
            return buf
    return count

count = make_count()
ans = 0

juwels = [1,4,1,4,2,1,3]
for i in range(len(["a","b","c","d"])): #(a+b+c+d).......
    ans += count(i,juwels)

juwels = [0,4,1,4,1,1,3]
for i in range(len(["b","c","d","e","f"])): #ea(b+c+d+e+f).....
    ans += count(i,juwels)

juwels = [0,4,0,4,1,1,2]
ans += count(i,juwels) #eagcb...

juwels = [0,4,0,3,1,1,2]
for i in range(len(["b","d","e"])): #eagcd(b+d+e)..
    ans += count(i,juwels)

print ans
