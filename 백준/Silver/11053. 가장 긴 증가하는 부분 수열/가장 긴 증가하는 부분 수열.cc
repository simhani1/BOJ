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
int N;
int arr[1001];
int dp[1001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        //모든 값들로부터 수열이 시작할 수 있으므로 1의 길이를 기본으로 가질수 있다.
        dp[i] = 1;
        for (int j = i - 1; j >= 1; j--)
        {
            //현재 값 이전 값들을 살피면서 본인보다 작은 값들의 수열의 길이 중 최대값을 찾는다.
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}