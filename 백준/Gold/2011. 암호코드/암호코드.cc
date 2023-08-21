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
#define MOD 1000000
typedef long long ll;

string str;
int dp[5001][2];

void input(void)
{
    cin >> str;
}

void solve(void)
{
    if (str[0] == '0')
    {
        cout << 0 << "\n";
        return;
    }
    dp[0][0] = 1;
    dp[0][1] = 0;
    for (int i = 1; i < str.length(); i++)
    {
        int ten = 10 * (str[i - 1] - '0');
        int one = str[i] - '0';
        int num = ten + one;
        if (num == 0)
        {
            cout << 0 << "\n";
            return;
        }
        if (one != 0)
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        if (10 <= num && num <= 26)
        {
            if (i == 1)
                dp[i][1] = 1;
            else
                dp[i][1] = (dp[i - 2][0] + dp[i - 2][1]) % MOD;
        }
    }
    cout << (dp[str.length() - 1][0] + dp[str.length() - 1][1]) % MOD << "\n";
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
