def f(a, b, k):
    if a > b or a == 222:
        return 0
    if a == b:
        return 1
    if a < b:
        s = str(a)+str(a**2 % 3)
        return f(a + 1, b, k + 1) + f(a + (a - 1) - k % 16, b, k + 1) + f(int(s), b, k + 1)
print(f(123, 321, 0))