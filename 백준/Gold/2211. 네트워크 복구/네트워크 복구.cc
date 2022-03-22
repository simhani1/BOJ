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

//도시 개수, 도로 개수, 거리 정보, 출발 도시 번호
int N, M;
int A, B, C;
vector<pii> edge[1001];
vector <int> dist;
int parent[1001];
const int INF = 1e9;

void dijkstra(int start) {
    //도시 번호, 거리
    priority_queue <pii> pq;
    dist.resize(N + 1, INF);
    pq.push({ start, 0 });
    dist[start] = 0;
    while (!pq.empty()) {
        int now = pq.top().first;
        int cost = -pq.top().second;
        pq.pop();
        if (dist[now] < cost)
            continue;
        for (int i = 0; i < edge[now].size(); i++) {
            int next = edge[now][i].first;
            int next_cost = edge[now][i].second;
            if (dist[next] > dist[now] + next_cost) {
                dist[next] = dist[now] + next_cost;
                pq.push({ next, -dist[next] });
                parent[next] = now;  //더 빠른 경로가 있을 경우 해당 노드의 부모 노드를 저장
            }
        }
    }
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        //완전 쌍방향 방식으로 통신이 되므로 양방향 간선을 모두 저장
        edge[A].push_back({ B,C });
        edge[B].push_back({ A,C });
    }
    dijkstra(1);
    cout << N - 1 << '\n';  //최소 n-1개 간선이 필요
    //n-1개의 연결된 노드 번호를 출력
    for (int i = 2; i <= N; i++) {
        cout << i << " " << parent[i] << '\n';
    }
    return 0;
}