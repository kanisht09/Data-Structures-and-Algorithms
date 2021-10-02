import math
def primefactors(n):
    fac = []
    while n % 2 == 0:
        fac.append(2)
        n = n // 2
    for i in range(3, int(math.sqrt(n)) + 2):
        while n % i == 0:
            fac.append(i)
            n = n // i
    if n > 1:
        fac.append(n)
    return sorted(fac)