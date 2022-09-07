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

int N, M;
int arr[100001];

int solve(void)
{
    int l = 0, r = 0, ans = 1234567890;
    while (r <= N)
    {
        if (arr[r] - arr[l] >= M)
        {
            ans = min(ans, arr[r] - arr[l]);
            l++;
        }
        else if (arr[r] - arr[l] < M)
            r++;
    }
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    cout << solve() << endl;
    return 0;
}
