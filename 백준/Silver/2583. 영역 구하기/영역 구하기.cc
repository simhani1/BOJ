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

int N, M, K;
int arr[100][100];
bool visited[100][100];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int cnt;
int cnt_ans = 0;
vector <int> v;

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < N && 0 <= ny && ny < M) {
            if (!visited[nx][ny] && arr[nx][ny] == 0) {
                cnt++;
                dfs(nx, ny);
            }
        }
    }
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> M >> N >> K;
    while (K--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i < x2; i++) {
            for (int j = y1; j < y2; j++) {
                arr[i][j] = 1;
                visited[i][j] = true;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0 && !visited[i][j]) {
                cnt = 1;
                dfs(i, j);
                v.push_back(cnt);
                cnt_ans++;
            }
        }
    }
    sort(v.begin(), v.end());
    cout << cnt_ans << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}