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
typedef long long ll;
typedef pair <ll, ll> pll;

int N, M, K;
int U, V, C;
vector <pll> edge[100001];
vector <ll> dist;
priority_queue <pll, vector<pll>, greater<pll>> pq;
bool visited[100001];
const ll INF = 999999999999;

void dijkstra(void) {
    while (!pq.empty()) {
        ll now = pq.top().first;
        ll nowCost = pq.top().second;
        pq.pop();
        if (nowCost > dist[now])
            continue;
        for (int i = 0; i < edge[now].size(); i++) {
            ll next = edge[now][i].first;
            ll nextCost = edge[now][i].second;
            if (dist[next] > dist[now] + nextCost) {
                dist[next] = dist[now] + nextCost;
                pq.push({ next, nextCost });
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    dist.resize(N + 1, INF);
    //면접장으로부터 집까지의 거리를 구하기 위해 간선 정보를 역으로 저장(면접장을 기준으로 간선 입력)
    for (int i = 0; i < M; i++) {
        cin >> U >> V >> C;
        edge[V].push_back({ U,C });
    }
    //면접 장소에서 각 집까지의 최단 경로를 모두 계산
    //결과적으로 각 면접장에서 집까지 갈 수 있는 모든 최단거리를 dist벡터에 저장 가능
    int interview;
    for (int i = 0; i < K; i++) {
        cin >> interview;
        pq.push({ interview, 0 });
        dist[interview] = 0;
    }
    dijkstra();
    ll maxDistance = 0;
    int idx;
    for (int i = 1; i <= N; i++) {
        if (dist[i] > maxDistance) {
            maxDistance = dist[i];
            idx = i;
        }
    }
    cout << idx << endl << maxDistance;
    return 0;
}