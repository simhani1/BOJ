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
#define MAX 987654321

int N, M;
int arr[5001];

bool check(int target)
{
    int nowMin = MAX, nowMax = 0, cnt = 1;
    for (int i = 0; i < N; i++)
    {
        nowMin = min(nowMin, arr[i]);
        nowMax = max(nowMax, arr[i]);
        if (nowMax - nowMin > target)
        {
            nowMax = arr[i];
            nowMin = arr[i];
            cnt++;
        }
    }
    if (cnt <= M)
        return true;
    return false;
}

int solve(void)
{
    int l = 0, r = 500000000, ans = MAX;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else
            l = mid + 1;
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
    cout << solve() << endl;
    return 0;
}
