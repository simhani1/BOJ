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

int M;

void input(void)
{
    cin >> M;
}

void solve(void)
{
    int l = 1, r = INF;
    int ans = INF;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int cnt = 0;
        for (int i = 5; i <= mid; i *= 5)
        {
            cnt += (mid / i);
        }
        if (cnt >= M)
        {
            if (cnt == M)
                ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    if (ans == INF)
        ans = -1;
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
