def checkio(data):
    # set parameter
    K = 3
    N = len(data)
    P = [ sum(data[:i+1]) for i in range(N) ]
    M = [ [0,]*K for i in range(N) ]

    # initialize the matrix M
    for i in range(N): M[i][0] = P[i]
    for j in range(K): M[0][j] = data[0]

    # loop process
    for i in range(1,N):
        for j in range(1,K):
            M[i][j] = min([ max(M[x][j-1], P[i]-P[x]) for x in range(i) ])

    print M
    return M[N-1][K-1]

#These "asserts" using only for self-checking and not necessary for auto-testing
if __name__ == '__main__':
    checkio(sorted([1,2,3,4,5,6,7,8,9,10,11,12],reverse=True))

    assert checkio([10, 10]) == 0, "1st example"
    assert checkio([10]) == 10, "2nd example"
    assert checkio([5, 8, 13, 27, 14]) == 3, "3rd example"
    assert checkio([5, 5, 6, 5]) == 1, "4th example"
    assert checkio([12, 30, 30, 32, 42, 49]) == 9, "5th example"
    assert checkio([1, 1, 1, 3]) == 0, "6th example"
