def checkio(data):
    m, n = len(data), len(data[0])
    trans = [[n,]*m for n in range(n)]
    # we cannot initialize 2-D list as following
    # but I can not locate what causes the problem
    #trans = [[0,]*m,]*n
    for i,row in enumerate(data):
        for j,col in enumerate(row):
            trans[j][i] = col
    return trans

# following code is posted in "clear" category
def clear(matr):
    return list(map(list, zip(*matr)))

if __name__ == '__main__':
    assert checkio([[1, 2, 3],
                    [4, 5, 6],
                    [7, 8, 9]]) == [[1, 4, 7],
                                    [2, 5, 8],
                                    [3, 6, 9]], "Square matrix"
    assert checkio([[1, 4, 3],
                    [8, 2, 6],
                    [7, 8, 3],
                    [4, 9, 6],
                    [7, 8, 1]]) == [[1, 8, 7, 4, 7],
                                    [4, 2, 8, 9, 8],
                                    [3, 6, 3, 6, 1]], "Rectangle matrix"
