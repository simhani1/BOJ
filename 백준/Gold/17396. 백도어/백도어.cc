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

ll N, M;
ll a, b, t;
const ll INF = 9223372036854775807;
bool check[100000];
vector<pair<ll, ll>> edge[100000];
vector <ll> dist(100000, INF);

void dijkstra(void) {
    priority_queue < pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({ 0,0 });
    dist[0] = 0;
    while (!pq.empty()) {
        //가중치가 음수로 저장돼 있으므로 양수로 바꿔서 사용
        ll now = pq.top().first;
        ll cost = pq.top().second;
        pq.pop();
        if (dist[now] < cost)
            continue;
        for (int i = 0; i < edge[now].size(); i++) {
            ll next = edge[now][i].first;
            ll nextcost = edge[now][i].second;
            if (dist[next] > dist[now] + nextcost) {
                dist[next] = dist[now] + nextcost;
                pq.push({ next,dist[next] });
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    //시야 정보 입력
    for (int i = 0; i < N; i++) {
        cin >> check[i];
    }
    check[N - 1] = false;
    while (M--) {
        cin >> a >> b >> t;
        //역방향 간선도 저장
        //상대 넥서스를 제외한 나머지 분기점들 시야가 안보이는 간선들만 저장
        if (check[a] != true && check[b] != true) {
            edge[a].push_back({ b,t });
            edge[b].push_back({ a,t });
        }
    }
    dijkstra();
    if (dist[N - 1] == INF)
        cout << -1;
    else
        cout << dist[N - 1];
    return 0;
}