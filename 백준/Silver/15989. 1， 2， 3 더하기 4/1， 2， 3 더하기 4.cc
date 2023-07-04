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

int T, N;
int dp[10001][4];

void init(void)
{
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    for (int i = 4; i <= 10000; i++)
    {
        dp[i][1] = dp[i - 1][1];
        dp[i][2] = dp[i - 2][2] + dp[i - 2][1];
        dp[i][3] = dp[i - 3][3] + dp[i - 3][2] + dp[i - 3][1];
    }
}

void input(void)
{
    cin >> T;
    init();
    while (T--)
    {
        cin >> N;
        cout << dp[N][1] + dp[N][2] + dp[N][3] << "\n";
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    return 0;
}
