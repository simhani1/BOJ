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
#include <sstream>
#include <cmath>
using namespace std;
#define INF 123456789
#define MOD 1000000
typedef long long ll;

int N, D;
vector<pair<int, int>> v;

void solve(void)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0;
    for (auto i : v)
    {
        int l = i.second - D;
        while (!pq.empty() && pq.top() < l)
        {
            pq.pop();
        }
        if (l <= i.first)
            pq.push(i.first);
        ans = max(ans, (int)pq.size());
    }
    cout << ans << "\n";
}

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
        return a.second < b.second;
    else
        return a.second < b.second;
}

void input(void)
{
    cin >> N;
    for (int i = 0, A, B; i < N; i++)
    {
        cin >> A >> B;
        v.push_back({min(A, B), max(A, B)});
    }
    sort(v.begin(), v.end(), compare);
    cin >> D;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}
