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

int N, M;
int c[5010], p[5010], dp[10001];

// dp[i] == i원 지출할 때 얻을 수 있는 최대 칼로리
// dp[i] = max(dp[i], dp[i-price[i]] + cost[i];
void solve(void)
{
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i - p[j] >= 0)
                dp[i] = max(dp[i], dp[i - p[j]] + c[j]);
        }
    }
    cout << dp[M] << "\n";
}

void init(void)
{
    fill(c, c + 5010, 0);
    fill(p, p + 5010, 0);
    fill(dp, dp + 10001, 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (true)
    {
        double m;
        cin >> N >> m;
        M = (int)(m * 100 + 0.5); // 7.99 라면 799가 되어야 한다
        if (N == 0 && M == 0)
            break;
        for (int i = 1, C; i <= N; i++)
        {
            double P;
            cin >> C >> P;
            c[i] = C;
            p[i] = (int)(P * 100 + 0.5);
        }
        solve();
        init();
    }
    return 0;
}
