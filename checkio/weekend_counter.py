from datetime import date,timedelta
def checkio(from_date, to_date):
    count = 0
    while (to_date - from_date).days > 7:
        count += 2
        to_date -= timedelta(days=7)

    fDow = from_date.weekday()
    tDow = to_date.weekday()

    if tDow > fDow:
        count += 1 if fDow >= 5 else 0
        count += 1 if tDow >= 5 else 0
    elif tDow < 5 and fDow < 5:
        count += 2
    elif tDow < 5:
        count += 2 if fDow == 5 else 1
    else:
        count += 3 if tDow == fDow else 2

    return count

#These "asserts" using only for self-checking and not necessary for auto-testing
if __name__ == '__main__':
    assert checkio(date(2013, 9, 18), date(2013, 9, 23)) == 2, "1st example"
    assert checkio(date(2013, 1, 1), date(2013, 2, 1)) == 8, "2nd example"
    assert checkio(date(2013, 2, 2), date(2013, 2, 3)) == 2, "3rd example"
    assert checkio(date(1999, 1, 1), date(2000, 1, 1)) == 105, "4th example"
