#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <time.h>
#include <map>

using namespace std;
typedef pair<int, int> pii;

int N, M, X;
int u, v, w;
vector<pii> edge[2][1001];
vector <int> dist[2];
const int INF = 1e9;

void dijkstra(int dir) {
    priority_queue <pii> pq;  //마을 번호, 가중치
    pq.push({ X,0 });
    dist[dir][X] = 0;
    while (!pq.empty()) {
        //가중치가 음수로 저장돼 있으므로 양수로 바꿔서 사용
        int now = pq.top().first;
        int cost = -pq.top().second;
        pq.pop();
        if (dist[dir][now] < cost)
            continue;
        for (int i = 0; i < edge[dir][now].size(); i++) {
            int next = edge[dir][now][i].first;
            int nextcost = edge[dir][now][i].second;
            if (dist[dir][next] > dist[dir][now] + nextcost) {
                dist[dir][next] = dist[dir][now] + nextcost;
                pq.push({ next,-dist[dir][next] });
            }
        }
    }
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> X;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        //노드, 연결된 노드, 가중치
        //역방향 간선도 저장
        edge[0][u].push_back({ v,w });  //X에서 각 마을로 가는 최단거리
        edge[1][v].push_back({ u,w });  //각 마을에서 X로 가는 최단거리
    }
    for (int i = 0; i < 2; i++) {
        dist[i].resize(N + 1, INF);
        dijkstra(i);
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, dist[0][i] + dist[1][i]);
    }
    cout << ans;
    return 0;
}