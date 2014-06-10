def checkio(data):
    if len(data) == 1: return data[0]

    data = [0,] + data
    N = sum(data)
    M = [ [False,]*len(data) for i in range(N+1) ]
    M[0] = [True,]*len(data)

    for i in range(1,len(M)):
        for j,d in enumerate(data):
            if M[i][j-1]:
                M[i][j] = True
            else:
                M[i][j] = True if i-d >= 0 and M[i-d][j-1] else False

    #for i,row in enumerate(M):
    #    print "%2d\t%r" % (i,row)

    for i,row in enumerate(M[:N/2+1][::-1]):
        print (N + N%2)/2 - i,row
        if sum(row) > 0:
            print "red:%d" % (2*i + N%2)
            return 2*i + N%2

    return -1

#These "asserts" using only for self-checking and not necessary for auto-testing
if __name__ == '__main__':
    print "1st"
    assert checkio([10, 10]) == 0, "1st example"
    print "2nd"
    assert checkio([10]) == 10, "2nd example"
    print "3rd"
    assert checkio([5, 8, 13, 27, 14]) == 3, "3rd example"
    print "4th"
    assert checkio([5, 5, 6, 5]) == 1, "4th example"
    print "5th"
    assert checkio([12, 30, 30, 32, 42, 49]) == 9, "5th example"
    print "6th"
    assert checkio([1, 1, 1, 3]) == 0, "6th example"
