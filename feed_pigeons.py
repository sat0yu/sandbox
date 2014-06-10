def checkio(N):
    return recursive(N, 0, 0)

def recursive(N, m, t):
    t += 1
    m += t
    if N > m:
        return recursive(N-m, m, t)
    else:
        return N if N > m - t else m - t

#These "asserts" using only for self-checking and not necessary for auto-testing
if __name__ == '__main__':
    assert checkio(1) == 1, "1st example"
    assert checkio(2) == 1, "2nd example"
    assert checkio(5) == 3, "3rd example"
    assert checkio(10) == 6, "4th example"
