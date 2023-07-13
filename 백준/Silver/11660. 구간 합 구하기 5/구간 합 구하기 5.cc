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

int N, M;
int dp[1025][1025];

void init(void)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            dp[i][j] += dp[i][j - 1];
        }
    }
    for (int j = 1; j <= N; j++)
    {
        for (int i = 1; i <= N; i++)
        {
            dp[i][j] += dp[i - 1][j];
        }
    }
}

void input(void)
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> dp[i][j];
        }
    }
    init();
    int A, B, C, D;
    while (M--)
    {
        cin >> A >> B >> C >> D;
        cout << dp[C][D] - dp[A - 1][D] - dp[C][B - 1] + dp[A - 1][B - 1] << "\n";
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
