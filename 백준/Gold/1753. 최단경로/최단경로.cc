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

int V, E, K;
int u, v, w;
vector <int> dist;
vector<vector<pii>> edge;
const int INF = 1e9;

void dijkstra() {
    dist.resize(V + 1, INF);
    dist[K] = 0;
    //가중치, 노드
    priority_queue <pii> pq;
    pq.push({ 0,K });
    while (!pq.empty()) {
        //가중치가 음수로 저장돼 있으므로 양수로 바꿔서 사용
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if (dist[here] < cost)
            continue;
        for (int i = 0; i < edge[here].size(); i++) {
            //이웃 노드
            int next = edge[here][i].first;
            //이웃 노드의 가중치
            int nextcost = edge[here][i].second;
            if (dist[next] > dist[here] + nextcost) {
                dist[next] = dist[here] + nextcost;
                //가중치가 작은 노드를 선택하기 위해 가중치를 음수로 바꿔서 저장
                pq.push({ -dist[next], next });
            }
        }
    }
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    //노드의 수, 간선의 수, 시작 정점
    cin >> V >> E >> K;
    edge.resize(V + 1);
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        edge[u].push_back({ v,w });
    }
    dijkstra();
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF)
            cout << "INF" << endl;
        else
            cout << dist[i] << endl;
    }
    return 0;
}