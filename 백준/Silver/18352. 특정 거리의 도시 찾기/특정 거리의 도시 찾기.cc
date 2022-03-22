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
int N, M, K, X;
int A, B;
vector<pii> edge[300001];
vector <int> dist;
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
            }
        }
    }
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> K >> X;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        edge[A].push_back({ B,1 });
    }
    dijkstra(X);
    bool flag = false;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == K) {
            cout << i << '\n';
            flag = true;
        }
    }
    if (!flag)
        cout << -1;
    return 0;
}