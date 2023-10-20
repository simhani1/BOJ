#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <cmath>
using namespace std;
#define INF 123456789
#define MOD 987654321
typedef long long ll;

int N;
ll dp[10010];

void solve(void)
{
    dp[0] = 1;
    dp[2] = 1;
    // dp[8] = dp[0] * dp[6] + dp[2] * dp[4] + dp[4] * dp[2] + dp[6] + dp[0];
    for (int i = 4; i <= N; i += 2)
    {
        for (int j = 0; j <= i - 2; j += 2)
        {
            dp[i] = (dp[i] + (dp[j] * dp[i - j - 2]) % MOD) % MOD;
        }
    }
    cout << dp[N] << "\n";
}

void input(void)
{
    cin >> N;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}
