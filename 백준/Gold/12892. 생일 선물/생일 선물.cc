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
#define MAX 2000000001
typedef long long ll;

int N, D;
vector<pair<ll, ll>> v;
ll pSum[100001];

ll solve(void)
{
    int l = 1, r = 1;
    ll ans = 0;
    while (l <= r && r <= N)
    {
        if (v[r].first - v[l].first < D)
        {
            if (r == N)
                ans = max(ans, pSum[r] - pSum[l - 1]);
            r++;
        }
        else
        {
            ans = max(ans, pSum[r - 1] - pSum[l - 1]);
            l++;
        }
    }
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> D;
    v.push_back({0, 0});
    for (int i = 0, P, V; i < N; i++)
    {
        cin >> P >> V;
        v.push_back({P, V});
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= N; i++)
        pSum[i] += (pSum[i - 1] + v[i].second);
    cout << solve() << "\n";
    return 0;
}
