#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;
#define INF 123456789
typedef long long ll;

int N;
vector<pair<int, ll>> v;
priority_queue<ll, vector<ll>, greater<ll>> pq;

ll solve(void)
{
    ll ans = 0;
    int now = 1;
    for (auto i : v)
    {
        int deadline = i.first;
        ll nowCnt = i.second;
        if (deadline >= now)
        {
            pq.push(nowCnt);
            now++;
        }
        else
        {
            if (nowCnt > pq.top())
            {
                pq.pop();
                pq.push(nowCnt);
            }
        }
    }
    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }
    return ans;
}

bool comp(pair<int, ll> p1, pair<int, ll> p2)
{
    if (p1.first == p2.first)
        return p1.second > p2.second;
    return p1.first < p2.first;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0, A; i < N; i++)
    {
        ll B;
        cin >> A >> B;
        v.push_back({A, B});
    }
    sort(v.begin(), v.end(), comp);
    cout << solve() << "\n";
    return 0;
}
