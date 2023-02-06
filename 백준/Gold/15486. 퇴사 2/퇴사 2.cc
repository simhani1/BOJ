#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <time.h>
#include <map>
#include <set>
using namespace std;
#define INF 2147483648
typedef long long ll;

int N;
ll T[1500001], P[1500001], dp[1500001];

ll solve(void)
{
    for (int i = N; i > 0; i--)
    {
        if (i + T[i] <= N + 1)
            dp[i] = max(dp[i + T[i]] + P[i], dp[i + 1]);
        else
            dp[i] = dp[i + 1];
    }
    return dp[1];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> T[i] >> P[i];
    }
    cout << solve() << "\n";
    return 0;
}
