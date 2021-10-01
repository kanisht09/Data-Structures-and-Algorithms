def SieveOfEratosthenes(n):
    prime = []
    primes = [True for i in range(n + 1)]
    p = 2
    while p * p <= n:
 
        if primes[p] == True:
            prime.append(p)
            for i in range(p * p, n + 1, p):
                primes[i] = False
        p += 1
    return prime