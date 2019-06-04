def isIPv4Address(IPv4):
    ipArr = IPv4.split('.')
    return len(ipArr) == 4 and all(n.isdigit() and  0 <= int(n) < 256 for n in ipArr)

print(isIPv4Address(input("Enter IPv4 : ")))