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
#define INF 2000000000
#define MOD 1000000007
typedef long long ll;

int N;
ll dp[1000001][2];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    dp[1][0] = 2;
    dp[2][0] = 7;
    dp[3][0] = 22;
    dp[3][1] = 1; // 특수한 케이스 계산을 위해
    for (int i = 4; i <= N; i++)
    {
        dp[i][1] = (dp[i - 3][0] + dp[i - 1][1]) % MOD;
        dp[i][0] = (2 * dp[i - 1][0] + 3 * dp[i - 2][0] + 2 * dp[i][1]) % MOD;
    }
    cout << dp[N][0] << "\n";
    return 0;
}
