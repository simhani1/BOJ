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

int N, M, K;
int arr[101][101];
bool visited[101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

int bfs(int x, int y) {
    int cnt = 1;
    queue <pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (1 <= nx && nx <= N && 1 <= ny && ny <= M) {
                if (arr[nx][ny] == 1 && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    cnt++;
                    q.push({ nx,ny });
                }
            }
        }
    }
    return cnt;
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> K;
    int a, b;
    while (K--) {
        cin >> a >> b;
        arr[a][b] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (arr[i][j] == 1 && !visited[i][j]) {
                ans = max(ans, bfs(i, j));
            }
        }
    }
    cout << ans;
    return 0;
}