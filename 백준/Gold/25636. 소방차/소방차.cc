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
#define MAX 9223372036854775807
typedef long long ll;

ll N, M, S, T;
vector<pair<ll, ll>> edge[100001];
ll arr[100001], dist[100001], water[100001];

void dijkstra(void)
{
    memset(dist, -1, sizeof(dist));
    // 가중치, 물탱크 양, 번호 순서로 저장
    // 가중치: 음수로 저장하여 최단 경로부터 탐색
    // 물탱크 양: 양수로 저장하여 물 양이 더 많은 정점부터 탐색
    priority_queue<pair<ll, pair<ll, int>>> pq;
    pq.push({0, {arr[S], S}});
    dist[S] = 0;
    water[S] = arr[S];
    while (!pq.empty())
    {
        ll now = pq.top().second.second;
        ll nowCost = -pq.top().first;
        ll nowWater = pq.top().second.first;
        pq.pop();
        if (dist[now] < nowCost || (dist[now] == nowCost && nowWater < water[now]))
            continue;
        for (int i = 0; i < edge[now].size(); i++)
        {
            ll next = edge[now][i].first;
            ll nextCost = nowCost + edge[now][i].second; // 다음노드까지 방문했을 때 거리
            ll nextWater = nowWater + arr[next];         // 다음노드까지 방문했을 때 물의양
            // 방문하지 않았거나, 최단거리가 갱신되거나, 최단거리는 같지만 물의양을 더많게 갱신해야 한다면 갱신하고, pq에 삽입
            if (dist[next] == -1 || dist[next] > nextCost || (dist[next] == nextCost && water[next] < nextWater))
            {
                dist[next] = nextCost;
                water[next] = nextWater;
                pq.push({-nextCost, {nextWater, next}});
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (ll i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    cin >> M;
    for (ll i = 0, A, B, C; i < M; i++)
    {
        cin >> A >> B >> C;
        edge[A].push_back({B, C});
        edge[B].push_back({A, C});
    }
    cin >> S >> T;
    dijkstra();
    if (dist[T] == -1)
        cout << -1 << "\n";
    else
        cout << dist[T] << " " << water[T] << "\n";
    return 0;
}
