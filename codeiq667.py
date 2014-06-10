#coding: utf-8;

for i in range(1,100+1):
    count = 1
    for j in range(1,i/2+1):
        count += 0 if (i % j) else 1
    if (count % 2):
        print i
