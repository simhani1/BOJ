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

int N, M;
int A, B, C;
vector <pair<int, ll>> edge[501];
vector <ll> dist;
const ll INF = 9223372036854775807;
bool flag = false;

void bellmanFord(int start) {
    dist[start] = 0;
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < edge[i].size(); j++) {
                int next = edge[i][j].first;
                ll nextCost = edge[i][j].second;
                //한번이라도 거리가 계산된 정점에 대해서만 갱신을 해야함
                if ((dist[i] != INF) && (dist[next] > dist[i] + nextCost)) {
                    dist[next] = dist[i] + nextCost;
                    //정점의 개수만큼 반복해서 값이 갱신되는 경우 음의 사이클 존재
                    if (k == N) {
                        flag = true;
                        break;
                    }
                }
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
        edge[A].push_back({ B,C });
    }
    dist.resize(N + 1, INF);
    bellmanFord(1);
    //음의 무한대로 발산
    if (flag)
        cout << -1;
    else {
        for (int i = 2; i <= N; i++) {
            if (dist[i] == INF)
                cout << -1 << endl;
            else
                cout << dist[i] << endl;
        }
    }
    return 0;
}