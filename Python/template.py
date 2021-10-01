import bisect
from itertools import accumulate, combinations, count
import os
import sys
import math
from decimal import *
from io import BytesIO, IOBase
from sys import maxsize
 
BUFSIZE = 8192
 
 
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
 
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
 
    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
 
 
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")
 
 
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
 
 
def input():
    return sys.stdin.readline().rstrip("\r\n")
 
 
def isPrime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i = i + 6
    return True
 
 
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
 
 
def factors(n):
    fac = set()
    fac.add(1)
    fac.add(n)
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            fac.add(i)
            fac.add(n // i)
    return list(fac)
 
 
def modInverse(a, m):
    m0 = m
    y = 0
    x = 1
    if m == 1:
        return 0
    while a > 1:
        q = a // m
        t = m
        m = a % m
        a = t
        t = y
        y = x - q * y
        x = t
    if x < 0:
        x = x + m0
    return x

def findXorSum(arr, n):
    Sum = 0
    mul = 1
    for i in range(30):
        c_odd = 0
        odd = 0
        for j in range(n):
            if ((arr[j] & (1 << i)) > 0):
                odd = (~odd)
            if (odd):
                c_odd += 1
        for j in range(n):
            Sum += (mul * c_odd)%(10**9+7)
 
            if ((arr[j] & (1 << i)) > 0):
                c_odd = (n - j - c_odd)
        mul *= 2
    return Sum%(10**9+7)
# -----------------------------------------------------code
