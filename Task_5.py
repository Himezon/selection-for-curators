def f(a, b):
    if int(a, base = 2) > int(b, base = 2)  or a == bin(74)[2:]:
        return 0
    if int(a, base = 2) == int(b, base = 2):
        return 1
    if int(a, base = 2) < int(b, base = 2):
        if a.count("1") % 2 == 0:
            s = a + "0"
        else:
            s = a + "1"
        return f(bin(int(a, base = 2) + 1)[2:], b) + f(bin(int(a, base = 2) * 3)[2:], b) + f(s, b)
print(f("111", bin(60)[2:]) * f(bin(60)[2:], "1111111"))