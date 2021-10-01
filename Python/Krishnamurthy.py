n=int(input())
sum=0
p=1
c=n
while(n>0):
    rem=n%10
    p=1
    for i in range(1,rem+1,1):
        p=p*i
    sum+=p
    n=n//10
if c==sum:
    print("Krishnamurthy")
else:
    print("Not krishnamurthy")
    