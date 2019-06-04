def centuryFromYear(year):

    return year//100 + (1 if year%100 > 0 else 0)