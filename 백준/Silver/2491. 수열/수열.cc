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
int ans = 1;

void solve(void)
{
    int len1 = 1, len2 = 1;
    for (int i = 1; i < N; i++)
    {
        if (arr[i] <= arr[i + 1])
            len1++;
        else
            len1 = 1;
        if (arr[i] >= arr[i + 1])
            len2++;
        else
            len2 = 1;
        ans = max(ans, max(len1, len2));
    }
}

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
    solve();
    cout << ans;
    return 0;
}