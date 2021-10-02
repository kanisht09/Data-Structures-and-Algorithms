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