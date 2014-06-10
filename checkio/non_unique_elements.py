from collections import Counter

def checkio33(data):
    count = Counter(data)
    count.subtract(set(data))
    # 3.3から単項加算（減算）をサポート
    # 単項加算（減算）は空カウンタの加算（からの減算）のショートカット
    return [x for x in data if x in +count]

def checkio27(data):
    # リストに含まれる特定の要素数はcountメソッドで受け取れる
    return [i for i in data if data.count(i) > 1]

def checkio(data):
    ret = []
    for e in data:
        if sum([ True if e == f else False for f in data]) > 1:
            ret.append(e)
    return ret

if __name__ == "__main__":
    assert isinstance(checkio33([1]), list)
    assert checkio33([1, 2, 3, 1, 3]) == [1, 3, 1, 3]
    assert checkio33([1, 2, 3, 4, 5]) == []
    assert checkio33([5, 5, 5, 5, 5]) == [5, 5, 5, 5, 5]
    assert checkio33([10, 9, 10, 10, 9, 8]) == [10, 9, 10, 10, 9]

    assert isinstance(checkio27([1]), list)
    assert checkio27([1, 2, 3, 1, 3]) == [1, 3, 1, 3]
    assert checkio27([1, 2, 3, 4, 5]) == []
    assert checkio27([5, 5, 5, 5, 5]) == [5, 5, 5, 5, 5]
    assert checkio27([10, 9, 10, 10, 9, 8]) == [10, 9, 10, 10, 9]

    assert isinstance(checkio([1]), list)
    assert checkio([1, 2, 3, 1, 3]) == [1, 3, 1, 3]
    assert checkio([1, 2, 3, 4, 5]) == []
    assert checkio([5, 5, 5, 5, 5]) == [5, 5, 5, 5, 5]
    assert checkio([10, 9, 10, 10, 9, 8]) == [10, 9, 10, 10, 9]
