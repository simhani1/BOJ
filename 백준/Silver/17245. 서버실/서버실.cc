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
#define MAX 10000000001
typedef long long ll;

ll N, M, sum = 0;
ll arr[1001][1001];

bool check(ll target)
{
    ll cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] > target)
                cnt += target;
            else
                cnt += arr[i][j];
        }
    }
    return ((double)cnt / sum) < 0.5;
}

ll solve(ll maxHeight)
{
    ll l = 0, r = maxHeight, ans = MAX;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (check(mid))
            l = mid + 1;
        else
        {
            r = mid - 1;
            ans = min(ans, mid);
        }
    }
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            sum += arr[i][j];
            M = max(M, arr[i][j]);
        }
    }
    cout << solve(M) << endl;
    return 0;
}
