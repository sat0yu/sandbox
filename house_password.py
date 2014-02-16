def checkio(data):
    if not len(data) >= 10:
        return False

    alphabet = set(data)
    digit = set([str(i) for i in range(10)])
    lower = set(['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'])
    upper = set(['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'])
    if not len( alphabet.intersection(digit) ) > 0:
        return False
    if not len( alphabet.intersection(lower) ) > 0:
        return False
    if not len( alphabet.intersection(upper) ) > 0:
        return False

    #replace this for solution
    return True

if __name__ == '__main__':
    assert checkio('A1213pokl') == False, "1st example"
    assert checkio('bAse730onE4') == True, "2nd example"
    assert checkio('asasasasasasasaas') == False, "3rd example"
    assert checkio('QWERTYqwerty') == False, "4th example"
    assert checkio('123456123456') == False, "5th example"
    assert checkio('QwErTy911poqqqq') == True, "6th example"
