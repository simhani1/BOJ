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

int N, R, G, B;
ll dp[11][101][101][101];

ll solve(int level, int nowR, int nowG, int nowB)
{
    if (nowR <= -1 || nowG <= -1 || nowB <= -1)
        return 0;
    if (level == 0)
        return 1;
    if (dp[level][nowR][nowG][nowB])
        return dp[level][nowR][nowG][nowB];

    // 한가지 색
    dp[level][nowR][nowG][nowB] += solve(level - 1, nowR - level, nowG, nowB);
    dp[level][nowR][nowG][nowB] += solve(level - 1, nowR, nowG - level, nowB);
    dp[level][nowR][nowG][nowB] += solve(level - 1, nowR, nowG, nowB - level);

    // 두가지 색
    if (level % 2 == 0)
    {
        if (level == 2)
        {
            dp[level][nowR][nowG][nowB] += (solve(level - 1, nowR - level / 2, nowG - level / 2, nowB) * 2);
            dp[level][nowR][nowG][nowB] += (solve(level - 1, nowR - level / 2, nowG, nowB - level / 2) * 2);
            dp[level][nowR][nowG][nowB] += (solve(level - 1, nowR, nowG - level / 2, nowB - level / 2) * 2);
        }
        else if (level == 4)
        {
            dp[level][nowR][nowG][nowB] += (solve(level - 1, nowR - level / 2, nowG - level / 2, nowB) * 6);
            dp[level][nowR][nowG][nowB] += (solve(level - 1, nowR - level / 2, nowG, nowB - level / 2) * 6);
            dp[level][nowR][nowG][nowB] += (solve(level - 1, nowR, nowG - level / 2, nowB - level / 2) * 6);
        }
        else if (level == 6)
        {
            dp[level][nowR][nowG][nowB] += (solve(level - 1, nowR - level / 2, nowG - level / 2, nowB) * 20);
            dp[level][nowR][nowG][nowB] += (solve(level - 1, nowR - level / 2, nowG, nowB - level / 2) * 20);
            dp[level][nowR][nowG][nowB] += (solve(level - 1, nowR, nowG - level / 2, nowB - level / 2) * 20);
        }
        else if (level == 8)
        {
            dp[level][nowR][nowG][nowB] += (solve(level - 1, nowR - level / 2, nowG - level / 2, nowB) * 70);
            dp[level][nowR][nowG][nowB] += (solve(level - 1, nowR - level / 2, nowG, nowB - level / 2) * 70);
            dp[level][nowR][nowG][nowB] += (solve(level - 1, nowR, nowG - level / 2, nowB - level / 2) * 70);
        }
        else if (level == 10)
        {
            dp[level][nowR][nowG][nowB] += (solve(level - 1, nowR - level / 2, nowG - level / 2, nowB) * 252);
            dp[level][nowR][nowG][nowB] += (solve(level - 1, nowR - level / 2, nowG, nowB - level / 2) * 252);
            dp[level][nowR][nowG][nowB] += (solve(level - 1, nowR, nowG - level / 2, nowB - level / 2) * 252);
        }
    }

    // 세가지 색
    if (level % 3 == 0)
    {
        if (level == 3)
            dp[level][nowR][nowG][nowB] += (solve(level - 1, nowR - level / 3, nowG - level / 3, nowB - level / 3) * 6);
        else if (level == 6)
            dp[level][nowR][nowG][nowB] += (solve(level - 1, nowR - level / 3, nowG - level / 3, nowB - level / 3) * 90);
        else if (level == 9)
            dp[level][nowR][nowG][nowB] += (solve(level - 1, nowR - level / 3, nowG - level / 3, nowB - level / 3) * 1680);
    }

    return dp[level][nowR][nowG][nowB];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> R >> G >> B;
    cout << solve(N, R, G, B) << "\n";
    return 0;
}
