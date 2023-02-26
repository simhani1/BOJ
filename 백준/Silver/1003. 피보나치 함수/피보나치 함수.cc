#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
#define INF 2147483648
typedef long long ll;

int T, N;
int dp[41][2];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    dp[0][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= 40; i++)
    {
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
    }
    while (T--)
    {
        cin >> N;
        cout << dp[N][0] << " " << dp[N][1] << endl;
    }
    return 0;
}
