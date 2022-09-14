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

int N;
long long arr[5001];
long long dp[5001][5001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    // 초기화
    for (int i = 1; i < N; i++)
    {
        dp[0][i] = i * (1 + abs(arr[i] - arr[0]));
    }
    // dp
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            dp[i][j] = min(dp[i - 1][j], max(dp[i - 1][i], (j - i) * (1 + abs(arr[i] - arr[j]))));
        }
    }
    cout << dp[N - 1][N - 1] << endl;
    return 0;
}
