def checkio(text):
    hashmap = {}
    alphabet = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
    for l in text:
        a = l.lower()
        if a in alphabet:
            if a in hashmap:
                hashmap[a] += 1
            else:
                hashmap[a] = 1

    letter, count = None, 0
    for l,c in sorted(hashmap.items()):
        if c > count:
            letter, count = l, c
    return letter

#These "asserts" using only for self-checking and not necessary for auto-testing
if __name__ == '__main__':
    assert checkio("Hello World!") == "l", "Hello test"
    assert checkio("How do you do?") == "o", "O is most wanted"
    assert checkio("One") == "e", "All letter only once."
    assert checkio("Oops!") == "o", "Don't forget about lower case."
    assert checkio("AAaooo!!!!") == "a", "Only letters."

