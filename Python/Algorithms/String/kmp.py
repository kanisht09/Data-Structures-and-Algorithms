'''
Calculates the prefix function (Knuth Morris Pratt) for the given string `s`
'''
def kmp(s):
    n = len(s)
    prefix = [0 for _ in range(n)]
    for i in range(1, n):
        j = prefix[i - 1]
        while j > 0 and s[i] != s[j]:
            j = prefix[j - 1]
        if s[i] == s[j]:
            j += 1
        prefix[i] = j
    return prefix