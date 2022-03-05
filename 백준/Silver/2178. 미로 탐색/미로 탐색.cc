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

int N, M;
int miro[100][100];
bool visited[100][100];
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (miro[nx][ny] == 1 && visited[nx][ny] == false) {
                    miro[nx][ny] = miro[x][y] + 1;
                    visited[nx][ny] = true;
                    q.push({ nx, ny });
                }
            }
        }
    }
}

int main(void) {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &miro[i][j]);
        }
    }
    bfs(0, 0);
    cout << miro[N - 1][M - 1];
    return 0;
}