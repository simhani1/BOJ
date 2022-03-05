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

int n, p, q, m;
vector <int> adj[101];
bool visited[101];
int ans;

void dfs(int now, int goal, int cnt) {
    visited[now] = 1;
    if (now == goal)
        ans = cnt;
    for (int i = 0; i < adj[now].size(); i++) {
        int next = adj[now][i];
        if (!visited[next]) {
            //cnt++을 안하는 이유: cnt를 직접적으로 건드리면 실제 정답보다 큰 수가 나올 수 있음
            //일단 방문 할대마다 cnt를 증가시키다 보면 문제가 발생할 수 있음
            dfs(next, goal, cnt + 1);
        }
    }
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> p >> q >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    dfs(p, q, 0);
    if (ans != 0)
        cout << ans;
    else
        cout << -1;
    return 0;
}