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

int T, K;
int dp[10001];
vector<pair<int, int>> v;

void input(void)
{
    cin >> T >> K;
    for (int i = 0, P, N; i < K; i++)
    {
        cin >> P >> N;
        v.push_back({P, N});
    }
}

int solve(void)
{
    dp[0] = 1;
    sort(v.begin(), v.end());
    for (int i = 0; i < K; i++)
    {
        for (int j = T; j >= 1; j--)
        {
            for (int cnt = 1; cnt <= v[i].second; cnt++)
            {
                int tmp = j - cnt * v[i].first;
                if (tmp < 0)
                    continue;
                dp[j] += dp[tmp];
            }
        }
    }
    return dp[T];
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
