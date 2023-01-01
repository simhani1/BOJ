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
#define MAX 98765432198765
typedef long long ll;

int T, K, N;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> K >> N;
        int dp[15][15];
        for (int i = 0; i <= K; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (i == 0)
                    dp[i][j] = j;
                else
                {
                    if (j == 1)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
            }
        }
        cout << dp[K][N] << "\n";
    }
    return 0;
}
