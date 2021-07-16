#Task 1
s = set()
def f(a, n):
    if n > 7:
        return 0
    if n == 7:
        s.add(a)
    k = 1
    while True:
        if (a + k) ** 0.5 == float(int((a + k) ** 0.5)):
            sl = int((a + k) ** 0.5)
            break
        k += 1
    while True:
        if (a - k) ** 0.5 == float(int((a - k) ** 0.5)):
            pr = int((a - k) ** 0.5)
            break
        k += 1
    sc = 0
    for i in str(a):
        sc += int(i)
    f(a + 1, n + 1)
    if a ** 0.5 == float(int(a ** 0.5)):
        f(a + 1, n + 1)
    else:
        f(a - pr + sl, n + 1)
    f(a + sc, n + 1)
f(7, 0)
print(len(s))

