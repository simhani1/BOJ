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

int T, N;
int arr[2][100001];
int dp[2][100001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> N;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> arr[i][j];
            }
        }
        // base case
        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        dp[0][1] = dp[1][0] + arr[0][1];
        dp[1][1] = dp[0][0] + arr[1][1];
        // 각 위치의 스티커를 제거할 때 얻는 최대 점수 계산
        for (int i = 2; i < N; i++)
        {
            dp[0][i] = arr[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
            dp[1][i] = arr[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
        }
        cout << max(dp[0][N - 1], dp[1][N - 1]) << endl;
    }
    return 0;
}
