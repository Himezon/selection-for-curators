s = set()
def f(a, n):
    if n > 5:
        return 0
    if n == 5:
        s.add(a)
    f(a + 1, n + 1)
    f(a * 3 // 2, n + 1)
    t = 0
    for i in str(a):
        t += int(i)
    f(a + t * 4, n + 1)
f(7, 0)
print(len(s))