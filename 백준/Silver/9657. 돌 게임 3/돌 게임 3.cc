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
#define MOD 1000000
typedef long long ll;

int N;
int dp[1001];

void input(void)
{
    cin >> N;
}

void solve(void)
{
    dp[1] = 1;
    dp[2] = -1;
    dp[3] = 1;
    dp[4] = 1;
    for (int i = 5; i <= N; i++)
    {
        dp[i] = -1;
        if (dp[i - 1] == -1)
            dp[i] = 1;
        if (dp[i - 3] == -1)
            dp[i] = 1;
        if (dp[i - 4] == -1)
            dp[i] = 1;
    }
    (dp[N] == 1) ? cout << "SK\n" : cout << "CY\n";
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
