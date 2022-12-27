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
#define MAX 1000000000
typedef long long ll;

int N, K;
int dp[11][11];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    cout << dp[N][K] << "\n";
    return 0;
}
