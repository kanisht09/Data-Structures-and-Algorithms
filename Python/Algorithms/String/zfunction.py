'''
Returns an array of elements z.
`z[i]` denotes the length of the longest string that is, at the same time,
a prefix of `s` and a prefix of the suffix of s starting at `i`.
'''
def z_function(s):
    n = len(s)
    z = [0 for _ in range(n)]
    i, l, r = 1, 0, 0
    while i < n:
        if i <= r:
            z[i] = min(r - i + 1, z[i - l])
        while i + z[i] < n and s[z[i]] == s[i + z[i]]:
            z[i] += 1
        if i + z[i] - 1 > r:
            l, r = i, i + z[i] - 1
        i += 1
    return z