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

int N, M, k;
int arr[50][50];
bool visited[50][50];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void dfs(int p, int q) {
    visited[p][q] = true;
    for (int i = 0; i < 4; i++) {
        int np = p + dx[i];
        int nq = q + dy[i];
        if (0 <= np && np < N && 0 <= nq && nq < M) {
            if (!visited[np][nq] && arr[np][nq] == 1)
                dfs(np, nq);
        }
    }
}

void reset_arr(void) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr[i][j] = 0;
        }
    }
}

void reset_visited(void) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = false;
        }
    }
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        //reset
        reset_arr();
        reset_visited();
        cin >> M >> N >> k;
        int x, y;
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            cin >> x >>  y;
            arr[y][x] = 1;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j] && arr[i][j] == 1) {
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}