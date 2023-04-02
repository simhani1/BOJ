#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;
#define INF 123456789
typedef long long ll;

int T, N;
int arr[40001], dp[40001];

int findIdx(int l, int r, int target)
{
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (dp[mid] < target)
            l++;
        else
            r--;
    }
    return r;
}

void solve(void)
{
    // j: lis 배열의 현재 인덱스, i: arr 배열의 현재 인덱스
    int j = 0, i = 1;
    dp[0] = arr[0];
    while (i < N)
    {
        if (dp[j] < arr[i])
        {
            dp[j + 1] = arr[i];
            j++;
        }
        else
        {
            int idx = findIdx(0, j, arr[i]);
            dp[idx] = arr[i];
        }
        i++;
    }
    cout << j + 1 << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> N;
        for (int i = 0, X; i < N; i++)
        {
            cin >> X;
            arr[i] = X;
        }
        solve();
        for (int i = 0; i < 40001; i++)
        {
            arr[i] = 0;
            dp[i] = 0;
        }
    }
    return 0;
}
