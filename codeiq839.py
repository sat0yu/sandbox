#coding: utf-8;
from __future__ import division, print_function, unicode_literals
from future_builtins import *

import string

def toAsciiNumberFromInteger(n):
    i, size = 1, len(string.ascii_lowercase)
    while n > size**i: i += 1

    asc = ""
    for j in reversed(range(i)):
        count = 0
        while n >= size**j:
            count += 1
            n -= size**j
        asc += string.ascii_lowercase[count-1]

    return asc

def toIntegerFromAsciiNumber(asc):
    def int(ch):
        return string.ascii_lowercase.find(ch) + 1

    integer = 0
    size = len(string.ascii_lowercase)
    for i,ch in enumerate(asc):
        integer += int(ch) * size**( len(asc) - (i+1) )
    return integer

def divide(sequence, n):
    if not len(sequence) > 0:
        return []
    else:
        return [sequence[:n]] + divide(sequence[n:],n)

def encode(word):
    transed = ""
    cur, count = word[0], 0
    word.strip()
    for c in word+"$":
        if cur == c:
            count += 1
        else:
            # append current symbol to transed words
            for asc in toAsciiNumberFromInteger(count):
                transed += ( cur + asc )
            # make preparation of next symbol
            cur = c
            count = 1

    return transed

def decode(seq):
    if len(seq) % 2 > 0:
        raise ValueError("Invalid Sequence.")
    word = ""
    for ch, cnt in divide(seq,2):
        word += ch * toIntegerFromAsciiNumber(cnt)
    return word

if __name__ == '__main__':
    filepath = "./data/spacetalky/words.txt"
    with open(filepath) as f:
        words = f.readlines()
        words = map(lambda x:x.strip(), words)
    for w in words:
        try:
            X = decode(w)
        except ValueError:
            X = 'X'
        print(':'.join([X,w]))
