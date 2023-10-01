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

int N, M, start, goal;
vector<pair<int, int>> v[1001];
vector<int> ans;
int route[1001];
int dist[1001];

void input(void)
{
    cin >> N >> M;
    for (int i = 0, A, B, C; i < M; i++)
    {
        cin >> A >> B >> C;
        v[A].push_back({B, C});
    }
    cin >> start >> goal;
}

void solve(void)
{
    for (int i = 0; i <= N; i++)
    {
        dist[i] = INF;
    }
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (now == goal)
            break;
        if (dist[now] < cost)
            continue;
        for (int i = 0; i < v[now].size(); i++)
        {
            int next = v[now][i].first;
            int nextCost = v[now][i].second;
            if (dist[next] > dist[now] + nextCost)
            {
                route[next] = now;
                dist[next] = dist[now] + nextCost;
                pq.push({-dist[next], next});
            }
        }
    }
    cout << dist[goal] << "\n";
    while (goal)
    {
        ans.push_back(goal);
        goal = route[goal];
    }
    cout << ans.size() << "\n";
    // 방문 순서 그대로 출력해야 하므로 정렬하지 말 것
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
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
