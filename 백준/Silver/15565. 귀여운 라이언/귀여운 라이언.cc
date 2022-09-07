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

int N, K;
int arr[1000001];

int solve(void)
{
    int l = 0, r = 0, pSum = 0, length = 99999999;
    while (r <= N)
    {
        if (pSum >= K)
        {
            pSum -= arr[l];
            l++;
        }
        else if (pSum < K)
        {
            pSum += arr[r];
            r++;
        }
        if (pSum == K)
            length = min(length, r - l);
    }
    return length;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if (arr[i] == 2)
            arr[i] = 0;
    }
    int ans = solve();
    if (ans == 99999999)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}
