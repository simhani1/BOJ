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

int N, M;
int start, goal;
int u, v, w;
vector <int> dist;
vector<vector<pii>> edge;
const int INF = 1e9;

void dijkstra() {
    dist.resize(N + 1, INF);
    dist[start] = 0;
    //비용, 도시 번호
    priority_queue <pii> pq;
    pq.push({ 0,start });
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
    //도시의 수, 버스의 개수
    cin >> N >> M;
    edge.resize(N + 1);
    for (int i = 0; i < M; i++) {
        //출발 도시 번호, 도착 도시 번호, 비용
        cin >> u >> v >> w;
        edge[u].push_back({ v,w });
    }
    cin >> start >> goal;
    dijkstra();
    cout << dist[goal];
    return 0;
}