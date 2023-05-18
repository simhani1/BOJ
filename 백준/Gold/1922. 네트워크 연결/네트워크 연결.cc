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
#define INF 123456789
typedef long long ll;

int N, M;
int parent[1001];
priority_queue<pair<int, pair<int, int>>> pq;

int Find(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    parent[y] = x;
}

void input(void)
{
    cin >> N >> M;
    for (int i = 0, A, B, C; i < M; i++)
    {
        cin >> A >> B >> C;
        pq.push({-C, {A, B}});
    }
}

void init(void)
{
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
}

int solve(void)
{
    int ans = 0;
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int from = Find(pq.top().second.first);
        int to = Find(pq.top().second.second);
        pq.pop();
        if (from != to)
        {
            Union(min(from, to), max(from, to));
            ans += cost;
        }
    }
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    init();
    cout << solve() << "\n";
    return 0;
}
