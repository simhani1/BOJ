n=int(input())
dp=[0, 0, 1]
for i in range(3, n+1):
    if i%2==0: dp.append(dp[i-1]*2+1)
    else: dp.append(dp[i-1]*2-1)
print(dp[n])