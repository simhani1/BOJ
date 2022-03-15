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

int N, M;
int arr[300][300];
bool visited[300][300];
queue <pair<int, int>> q;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void bfs(int a, int b) {
    q.push({ a,b });
    visited[a][b] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < M && !visited[nx][ny]) {
                //주변이 바다일 경우
                //바로 전 좌표가 빙산일 경우 빙산 감소
                //바로 전 좌표가 바다일 경우 그냥 0으로 유지
                if (arr[nx][ny] == 0)
                    arr[x][y] = (arr[x][y] == 0) ? 0 : arr[x][y] - 1;
                //주변이 빙산일 경우
                //바다였다면 다른 빙산에서도 같은 바다를 방문할 수 있기 때문에 방문처리를 하면 안됨
                else {
                    visited[nx][ny] = true;
                    q.push({ nx,ny });
                }
            }
        }
    }
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    int T = 0;
    while (1) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                //빙산들만 bfs로 탐색
                if (arr[i][j] != 0 && !visited[i][j]) {
                    bfs(i, j);
                    cnt++;  //빙산의 개수 저장
                }
            }
        }
        //빙산이 2개로 쪼개지는 경우 중지
        if (cnt >= 2) {
            cout << T;
            break;
        }
        //빙산이 모두 녹아버렸을 경우 중지
        else if (cnt == 0) {
            cout << 0;
            break;
        }
        //최초로 2개 이상의 빙산으로 나눠지는지 체크를 해야하므로 빙산의 개수를 모두 센 후 시간이 더해져야 함
        T++;
        memset(visited, 0, sizeof(visited));
    }
    return 0;
}