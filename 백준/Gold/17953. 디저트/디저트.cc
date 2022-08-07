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

int N, M;
int arr[11][100001];
int dp[11][100001];

void solve(void)
{
    // base case
    for (int desert = 1; desert <= M; desert++)
    {
        dp[desert][1] = arr[desert][1];
    }
    // dp
    for (int day = 2; day <= N; day++)
    {
        for (int desert = 1; desert <= M; desert++)
        {
            for (int prevDesert = 1; prevDesert <= M; prevDesert++)
            {
                // 전날과 동일한 디저트를 먹는 경우
                if (desert == prevDesert)
                    dp[desert][day] = max(dp[desert][day], dp[prevDesert][day - 1] + arr[desert][day] * 1 / 2);
                // 전날과 다른 디저트를 먹는 경우
                else
                    dp[desert][day] = max(dp[desert][day], dp[prevDesert][day - 1] + arr[desert][day]);
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int desert = 1; desert <= M; desert++)
    {
        for (int day = 1; day <= N; day++)
        {
            cin >> arr[desert][day];
        }
    }
    solve();
    int ans = 0;
    for (int desert = 1; desert <= M; desert++)
    {
        ans = max(ans, dp[desert][N]);
    }
    cout << ans;
    return 0;
}
