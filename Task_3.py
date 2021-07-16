def f(a, b):
    if a < b or a == 19:
        return 0
    if a == b:
        return 1
    if a > b:
        return f(a - 1, b) + f(a - 3, b) + f(a - 11, b)
print(f(32,25)*f(25,16))