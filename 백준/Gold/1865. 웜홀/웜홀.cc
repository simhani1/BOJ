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

int N, M, W;
int S, E, T;
vector <pair<int, int>> edge[501];
vector <int> dist;
const int INF = 1e9;
bool flag;

void bellmanFord(int start) {
    dist[start] = 0;
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < edge[i].size(); j++) {
                int next = edge[i][j].first;
                int nextCost = edge[i][j].second;
                //시작 정점에서 연결된 정점이 아니더라도 음의 사이클 존재여부만 확인하면 됨
                //따라서 dist[next]!=INF 조건이 필요없음
                if (dist[next] > dist[i] + nextCost) {
                    dist[next] = dist[i] + nextCost;
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
    int TC;
    cin >> TC;
    while (TC--) {
        cin >> N >> M >> W;
        for (int i = 1; i <= N; i++) {
            edge[i].clear();
        }
        dist.resize(N + 1, INF);
        //경로 정보 입력
        for (int i = 0; i < M; i++) {
            cin >> S >> E >> T;
            edge[S].push_back({ E,T });
            edge[E].push_back({ S,T });
        }
        //웜홀 정보 입력
        for (int i = 0; i < W; i++) {
            cin >> S >> E >> T;
            edge[S].push_back({ E,-T });
        }
        //각각의 정점을 시작으로 벨만포드 수행
        flag = false;
        bellmanFord(1);
        //음의 사이클이 존재하는 경우
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}