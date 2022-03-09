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
#include <memory.h>

using namespace std;

int w, h;
int arr[50][50];
int visited[50][50];
int dx[] = { 1,1,0,-1,-1,-1,0,1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < h && 0 <= ny && ny < w) {
            if (!visited[nx][ny] && arr[nx][ny] == 1) {
                visited[nx][ny] = true;
                dfs(nx, ny);
            }
        }
    }
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> arr[i][j];
            }
        }
        int cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (arr[i][j] == 1 && !visited[i][j]) {
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        cout << cnt << endl;
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
    }
    return 0;
}