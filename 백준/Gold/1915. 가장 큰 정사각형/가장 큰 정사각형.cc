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
#define INF 1234567890
typedef long long ll;

int N, M;
int arr[1001][1001], dp[1001][1001];

void input(void)
{
    cin >> N >> M;
    string str;
    for (int i = 1; i <= N; i++)
    {
        cin >> str;
        for (int j = 0; j < M; j++)
        {
            arr[i][j + 1] = (str[j] - '0');
            if (arr[i][j + 1] == 1)
                dp[i][j + 1] = 1;
        }
    }
}

void solve(void)
{
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (!dp[i][j])
                continue;
            dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            ans = max(ans, dp[i][j]);
        }
    }
    ans *= ans;
    cout << ans << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}
