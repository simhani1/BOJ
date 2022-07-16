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
int arr[100001];
int dp[100001];

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
    dp[1] = arr[1];
    int ans = arr[1];
    for (int i = 1; i <= N; i++)
    {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}
