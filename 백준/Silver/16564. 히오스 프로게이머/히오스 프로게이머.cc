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
#define MAX 123456789
typedef long long ll;

ll N, K, ans = 0;
ll arr[1000001];

bool check(ll target)
{
    ll sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] <= target)
            sum += (target - arr[i]);
    }
    return sum <= K;
}

ll solve(void)
{
    ll l = 0, r = 2000000000;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (check(mid))
        {
            ans = max(ans, mid);
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return ans;
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
    }
    cout << solve() << "\n";
    return 0;
}
