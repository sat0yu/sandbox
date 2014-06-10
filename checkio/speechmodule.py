FIRST_TEN = ["one", "two", "three", "four", "five", "six", "seven",
             "eight", "nine"]
SECOND_TEN = ["ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
              "sixteen", "seventeen", "eighteen", "nineteen"]
OTHER_TENS = ["twenty", "thirty", "forty", "fifty", "sixty", "seventy",
              "eighty", "ninety"]
HUNDRED = "hundred"

def checkio(number):
    a, b, c = "", "", ""
    w, x, y, z = 0, 0, 0, 0
    while number > 0:
        print number
        if number >= 100:
            w += 1
            number -= 100
        elif y == 0 and 9 < number < 20:
            x = number - 9
            number = 0
        elif number >= 10:
            y += 1
            number -= 10
        else:
            z += 1
            number -= 1

    print w,x,y,z
    if w > 0:
        a = " ".join((FIRST_TEN[w-1],HUNDRED))
        if x == y == z == 0:
            return a
    if x > 0:
        b = SECOND_TEN[x-1]
        if w > 0:
            print " ".join((a,b))
            return " ".join((a,b))
        else:
            print b
            return b
    if y > 0:
        b = OTHER_TENS[y-2]
        if not z > 0:
            if w > 0:
                print " ".join((a,b))
                return " ".join((a,b))
            else:
                print b
                return b
    if z > 0:
        c = FIRST_TEN[z-1]
        if w > 0 and y > 0:
            print " ".join((a,b,c))
            return " ".join((a,b,c))
        elif w > 0:
            print " ".join((a,c))
            return " ".join((a,c))
        elif y > 0:
            print " ".join((b,c))
            return " ".join((b,c))
        else:
            print c
            return c

#Some hints
#Don't forget strip whitespaces at the end of string


#These "asserts" using only for self-checking and not necessary for auto-testing
if __name__ == '__main__':
    assert checkio(4) == 'four', "1st example"
    assert checkio(133) == 'one hundred thirty three', "2nd example"
    assert checkio(12) == 'twelve', "3rd example"
    assert checkio(101) == 'one hundred one', "4th example"
    assert checkio(212) == 'two hundred twelve', "5th example"
    assert checkio(40) == 'forty', "6th example"
