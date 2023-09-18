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
#define INF 1e9
#define MOD 1000000
typedef long long ll;

int N, T;
int daySum = 0, feeSum = 0;
int weight[1001], value[1001], dp[1001][1001];

void input()
{
    cin >> N >> T;
    for (int i = 1, A, B; i <= N; i++)
    {
        cin >> weight[i] >> value[i];
        daySum += weight[i];
        feeSum += value[i];
    }
}

void solve(void)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= T; j++)
        {
            if (j >= weight[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    if (daySum == T)
        cout << 0 << "\n";
    else
        cout << feeSum - dp[N][T] << "\n";
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
