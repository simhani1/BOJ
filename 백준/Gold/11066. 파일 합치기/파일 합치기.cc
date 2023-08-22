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

int T, K;
int arr[501], pSum[501], dp[501][501];

void init(void)
{
    for (int i = 0; i < 501; i++)
    {
        arr[i] = 0;
        pSum[i] = 0;
        for (int j = 0; j < 501; j++)
        {
            dp[i][j] = 0;
        }
    }
}

void solve(void)
{
    // i: i개의 원소를 합치는 경우
    for (int i = 1; i <= K; i++)
    {
        // j: 구간의 시작 인덱스
        for (int j = 1; j <= K - i; j++)
        {
            dp[j][j + i] = INF;
            // k: 구간을 나누는 기준점
            for (int k = j; k < j + i; k++)
            {
                dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + pSum[j + i] - pSum[j - 1]);
            }
        }
    }
}

void input(void)
{
    cin >> T;
    while (T--)
    {
        cin >> K;
        for (int i = 1; i <= K; i++)
        {
            cin >> arr[i];
            pSum[i] += pSum[i - 1] + arr[i];
        }
        solve();
        cout << dp[1][K] << "\n";
        init();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    return 0;
}
