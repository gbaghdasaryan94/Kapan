ch1 = input('ch1 = ')
ch2 = input('ch2 = ')


def add_tags(ch1, ch2):
    s = '<' + ch1 + '>' + ch2 + '</' + ch1 + '>'
    return s


print(add_tags(ch1, ch2))
