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
#define MAX_VALUE 1234567891011
typedef long long ll;

ll T, N;
ll arr[100001], tmp[100001];
ll minHeight = MAX_VALUE;

int check(ll std)
{
    if (std >= 0)
    {
        for (int i = 0; i < N - 1; i++)
        {
            if (tmp[i] >= std)
            {
                ll diff = tmp[i] - std;
                tmp[i] -= diff;
                tmp[i + 1] -= diff;
            }
            else
                return -1;
        }
        if (tmp[N - 1] == std)
            return 0;
        else if (tmp[N - 1] > std)
            return 1;
        else if (tmp[N - 1] < std)
            return -1;
    }
    return -1;
}

ll solve(void)
{
    ll l = 0, r = minHeight, cnt = 0;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        copy(arr, arr + N, tmp);
        int result = check(mid);
        if (result == 0 || result == 1)
        {
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    int result = check(r);
    if (result == 0)
    {
        for (int i = 0; i < N - 1; i++)
        {
            ll diff = arr[i] - r;
            cnt += diff;
            arr[i] -= diff;
            arr[i + 1] -= diff;
        }
        return cnt * 2;
    }
    else
        return -1;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> N;
        minHeight = MAX_VALUE;
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
            minHeight = min(minHeight, arr[i]);
        }
        cout << solve() << endl;
    }
    return 0;
}
