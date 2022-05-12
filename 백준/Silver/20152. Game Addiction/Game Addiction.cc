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

using namespace std;

int H, N;
int start, goal, ans;
long long dp[31][31];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> H >> N;
    if (H < N)
    {
        start = H;
        goal = N;
    }
    else if (H > N)
    {
        start = N;
        goal = H;
    }
    else
    {
        cout << 1;
        return 0;
    }
    //초기값 설정
    for (int i = 0; i <= 30; i++)
    {
        for (int j = 0; j <= 30; j++)
        {
            if (i >= j)
                dp[i][j] = 1;
        }
    }
    // dp
    for (int i = start; i <= goal; i++)
    {
        for (int j = start; j <= i; j++)
        {
            if (start < i && i <= goal && start < j && j <= goal)
            {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
    }
    cout << dp[goal][goal];
    return 0;
}