array = set()
def f(a,k):
    if k > 15:
        return 0
    if k == 15:
        array.add(a)
    f(bin(int(a, base=2)-1)[2:], k+1)
    if int(a, base=2) ** 0.5 == float(int(int(a, base=2) ** 0.5)):
        f(bin(int(int(a, base=2)**0.5))[2:], k+1)
    if a[1] == "1":
        f(a[1:], k+1)
f("1"+123*"0", 0)
print(len(array))