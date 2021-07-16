def f(a, b):
    if a > b or a == 220:
        return 0
    if a == b:
        return 1
    if a < b:
        return f(a + 1, b) + f(a * 2, b) + f(int(str(a)+str(a)[-1:]), b)
print(f(3, 110) * f(110, 333))