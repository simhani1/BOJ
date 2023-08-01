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
#define INF 2000000000
typedef long long ll;

int N;
int arr[500001], tmp[500001];
ll ans = 0;

void merge(int start, int mid, int end)
{
    int i = start, j = mid + 1, k = start, cnt = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
            tmp[k++] = arr[i++];
        else
        {
            tmp[k++] = arr[j++];
            ans += (j - k);
        }
    }
    if (i > mid)
    {
        for (int t = j; t <= end; t++)
        {
            tmp[k++] = arr[t];
        }
    }
    else
    {
        for (int t = i; t <= mid; t++)
        {
            tmp[k++] = arr[t];
        }
    }
    for (int t = start; t <= end; t++)
    {
        arr[t] = tmp[t];
    }
}

void solve(int start, int end)
{
    if (start >= end)
        return;
    int mid = (start + end) / 2;
    solve(start, mid);
    solve(mid + 1, end);
    merge(start, mid, end);
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
    solve(1, N);
    cout << ans << "\n";
    return 0;
}
