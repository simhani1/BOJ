#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <time.h>

using namespace std;

bool visited_bfs[101];
vector <int> adj[1001];
int N, M;
int cnt = 0;

int bfs(int now) {
    queue <int> q;
    visited_bfs[now] = 1;
    q.push(now);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < adj[now].size(); i++) {
            int next = adj[now][i];
            if (!visited_bfs[next]) {
                visited_bfs[next] = 1;
                q.push(next);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int p, q;
        cin >> p >> q;
        adj[p].push_back(q);
        adj[q].push_back(p);
    } 
    for (int i = 1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    cout << bfs(1);
    return 0;
}