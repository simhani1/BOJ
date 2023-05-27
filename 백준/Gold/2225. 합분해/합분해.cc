#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define INF 123456789
typedef long long ll;

int N, K;
int dp[201][201];

void input(void)
{
    cin >> N >> K;
}

int solve(void)
{
    for (int i = 0; i <= N; i++)
    {
        dp[1][i] = 1;
    }
    for (int k = 2; k <= K; k++)
    {
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                dp[k][i] = (dp[k][i] + dp[k - 1][i - j]) % 1000000000;
            }
        }
    }
    return dp[K][N];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    cout << solve() << "\n";
    return 0;
}
