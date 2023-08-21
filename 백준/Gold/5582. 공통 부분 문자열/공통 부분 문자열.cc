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
#include <sstream>
using namespace std;
#define INF 2000000000
typedef long long ll;

string S, T;
int dp[4001][4001];

void input(void)
{
    cin >> S >> T;
}

void solve(void)
{
    int ans = 0;
    for (int i = 0; i < S.length(); i++)
    {
        for (int j = 0; j < T.length(); j++)
        {
            if (S[i] == T[j])
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans << "\n";
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
