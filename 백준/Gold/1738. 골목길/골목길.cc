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
int U, V, W;
vector <pii> edge[101];
vector <int> edgePossible[101];
vector <int> dist;
queue <int> q;
int parentNode[101];
bool visited[101];
bool isCycle;
const int INF = 999999999;

//콘도에서부터 갈 수 있는 골목길들을 true로 체크
void bfs(int start) {
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < edgePossible[now].size(); i++) {
            int next = edgePossible[now][i];
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

void bellmanFord(int start) {
    isCycle = false;
    dist[start] = 0;
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < edge[i].size(); j++) {
                int next = edge[i][j].first;
                int nextCost = edge[i][j].second;
                //if문 안으로 들어가는 경우 값의 갱신이 발생
                if (dist[i] != INF && dist[next] > dist[i] + nextCost) {
                    dist[next] = dist[i] + nextCost;
                    parentNode[next] = i;  //방문한 정점의 부모 노드를 저장(경로 출력을 휘해)
                    //음의 사이클 존재할 경우
                    if (k == N) {
                        //해당 정점이 콘도에서 도달 가능한 정점일 경우, 콘도까지 가는 경로에 음의 사이클이 존재하는 것
                        if (visited[next])
                            isCycle = true;
                    }
                }
            }
        }
    }
}

//콘도까지의 경로를 재귀함수를 통해 출력
void printPath(int node) {
    if (node == 1)
        cout << node << " ";
    else {
        printPath(parentNode[node]);
        cout << node << " ";
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> U >> V >> W;
        //벨만포드는 최단 경로를 찾는 알고리즘, but 획득 가능한 금품의 최대 양을 구해야 하므로 부호를 반대로 저장
        //금품의 양이 많을 수록 값이 최소가 되면서 dist 배열에 최대 획득량의 음의 값이 저장됨
        edge[U].push_back({ V,-W });
        //콘도를 시작으로 도달가능한 정점들을 체크하기 위해 역 간선 정보를 저장
        edgePossible[V].push_back(U);
    }
    //콘도로부터 도달 가능한 정점들을 체크
    bfs(N);
    //시작점부터 콘도까지의 최단 경로를 구하기
    dist.resize(N + 1, INF);
    bellmanFord(1);
    //콘도까지 가는 경로에 음의 사이클이 존재
    if (isCycle)
        cout << -1;
    else
        printPath(N);
    return 0;
}