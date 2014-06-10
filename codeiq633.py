#coding: utf-8;
import numpy as np

#// 教科データ
category=['Ja','Ma','En','So','Sc','Mu','Ar']
#// 海平怒りのスコア初期値
#score=[35,15,20,30,25,15,25]
#// 海平怒りの倍数（7日分
#multiplier=[
#    [1,1,2,3,5,8,13],
#    [1,5,9,13,17,21,25],
#    [1,5,8,12,15,19,22],
#    [1,3,5,7,9,11,13],
#    [1,2,4,6,8,10,12],
#    [1,4,6,9,11,14,16],
#    [1,2,2,3,5,8,11],
#]
matrix = np.array([
    [35,35,70,105,175,280,455],
    [15,75,135,195,255,315,375],
    [20,100,160,240,300,380,440],
    [30,90,150,210,270,330,390],
    [25,50,100,150,200,250,300],
    [15,60,90,135,165,210,240],
    [25,50,50,75,125,200,275],
])

class Tree:
    class node:
        def __init__(self, value, indices=None, parent=None, isRoot=False):
            self.__children = []
            self.value = value
            self.indices = indices
            self.isRoot = isRoot
            if parent is not None:
                self.setParent(parent)
        def setParent(self, n):
            n.addChild(self)
            self.__parent = n
        def addChild(self, n):
            self.__children.append(n)
        def getChildren(self):
            return self.__children
        def getParent(self):
            return self.__parent
        def getAncestors(self):
            p, anc = self, [self,]
            while not p.isRoot:
                p = p.getParent()
                anc.append(p)
            return anc

    def __init__(self, matrix):
        self.root = Tree.node(0, isRoot=True)
        self.__mat = matrix
        self.createFromMatrix(parent=self.root)

    def createFromMatrix(self, parent=None, ancestor=[], depth=0):
        for i in [i for i in range(self.__mat.shape[0]) if not i in ancestor]:
            anc = ancestor[:]
            anc.append(i)
            indices=(i,depth)
            n = Tree.node( value=self.__mat[indices], indices=indices, parent=parent)
            self.createFromMatrix(parent=n, ancestor=anc, depth=depth+1)

# explorer tree in depth-first
t = Tree( np.fliplr(matrix) )
stack = [t.root,]
min_cost = sum(sum(matrix))
while len(stack) != 0:
    n = stack.pop()
    anc = n.getAncestors()
    cost = sum([a.value for a in anc])
    # cut unuseless branch
    if cost < min_cost:
        # update min_cost
        if len(anc) == 1 + matrix.shape[1]:
            min_cost = cost
            order = anc
        # stack child nodes in decending
        chd = [ (c.value, c) for c in n.getChildren() ]
        chd.sort(reverse=True)
        for i,c in chd:
            stack.append(c)

result = [ category[a.indices[0]] for a in order[:-1] ]
print "見せる順番：%s" % "->".join(result)
print "怒りのスコア：%d" % min_cost
