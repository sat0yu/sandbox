VOWELS = "AEIOUY"
CONSONANTS = "BCDFGHJKLMNPQRSTVWXZ"

import string
class checker:
    def __init__(self, word):
        self.word = word.upper()
        self.next = 0 if self.word[0] in VOWELS else 1

    def pop(self):
        c = self.word[0]
        if ( self.next == 0 and c in VOWELS ) \
                or ( self.next == 1 and c in CONSONANTS ):
            self.next = 1 if self.next == 0 else 0
            self.word = self.word[1:]
            return True
        else:
            return False

    def isStripe(self):
        if not len(self.word) > 1: return False
        while len(self.word) > 0:
            if not self.pop(): return False
        return True

def checkio(data):
    data = data\
            .replace(",", " ")\
            .replace(".", " ")\
            .replace("!", " ")\
            .replace("?", " ")
    words = data.split()
    return sum([checker(w).isStripe() for w in words])

#These "asserts" using only for self-checking and not necessary for auto-testing
if __name__ == '__main__':
    assert checkio(u"My name is ...") == 3, "All words are striped"
    assert checkio(u"Hello world") == 0, "No one"
    assert checkio(u"A quantity of striped words.") == 1, "Only of"
    assert checkio(u"Dog,cat,mouse,bird.Human.") == 3, "Dog, cat and human"
