#coding: utf-8;
class Combination:
    def __init__(self, items):
        self.items = items
        self.n = len(items)
        self.bits = [0,]*self.n

    def enumerate(self, k):
        for i in range(2 ** self.n):
            binary = [ 1 if bit == '1' else 0 for bit in format(i, '0%db' % self.n) ]
            if sum(binary) == k:
                yield [ self.items[p] for p,q in enumerate(binary) if q == 1 ]

def makeHashKey(list_obj):
    return ''.join( [ str(i) for i in sorted(list_obj[:]) ] )

if __name__ == '__main__':
    # initialize
    digits = {
        '0': "1111110",
        '1': "0110000",
        '2': "1101101",
        '3': "1111001",
        '4': "0110011",
        '5': "1011011",
        '6': "1011111",
        '7': "1110000",
        '8': "1111111",
        '9': "1111011",
    }
    comb = Combination(digits.keys())
    W = {}
    for e in comb.enumerate(2):
        W[makeHashKey(e)]\
                = sum([ 1 if s != t else 0 for s,t in zip(digits[e[0]],digits[e[1]]) ])

    # Dynamic Programming
    B = {}
    for digit in comb.enumerate(1):
        B[makeHashKey(digit)] = {digit[0]:0}
    for n in range(1,10):
        for S_list in comb.enumerate(n):
            S = set(S_list)
            S_str = makeHashKey(S_list)
            for i in S:
                #print S,set(digits.keys()) - S
                for j in (set(digits.keys()) - S):
                    SJ_list = S_list + [j,]
                    SJ = set(SJ_list)
                    SJ_str = makeHashKey(SJ_list)
                    if not B.has_key(SJ_str): B[SJ_str] = {}
                    cost = B[S_str][i] + W[makeHashKey([i,j])]
                    B[SJ_str][j] = cost if cost < B[SJ_str].get(j, float("inf")) else B[SJ_str][j]

    print min(B['0123456789'].values())
