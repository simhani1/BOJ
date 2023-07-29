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
#define INF 2000000000
typedef long long ll;

int N, K;
int dp[1000001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for (int i = 0; i <= 1000000; i++)
    {
        dp[i] = INF;
    }
    dp[0] = 0;
    for (int i = 0; i < N; i++)
    {
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        if (i + i / 2 <= N)
            dp[i + i / 2] = min(dp[i + i / 2], dp[i] + 1);
    }
    if (dp[N] <= K)
        cout << "minigimbob\n";
    else
        cout << "water\n";
    return 0;
}
