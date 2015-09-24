m = int(raw_input())
d = int(raw_input())
if d==0:
    print('NO')
elif not(m % d):
    print('YES')
else:
    print('NO')
