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
using namespace std;
#define INF 1234567890
typedef long long ll;

int N;
int arr[1001], dp[1001], reverseDp[1001];

void input(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
}

void solve(void)
{
    for (int i = 0; i < N; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    for (int i = N - 1; i >= 0; i--)
    {
        reverseDp[i] = 1;
        for (int j = N - 1; j > i; j--)
        {
            if (arr[j] < arr[i])
                reverseDp[i] = max(reverseDp[i], reverseDp[j] + 1);
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans = max(ans, dp[i] + reverseDp[i] - 1);
    }
    cout << ans << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}
