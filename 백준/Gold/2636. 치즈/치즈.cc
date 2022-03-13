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
int arr[100][100];
bool visited[100][100];
queue <pair<int, int>> q;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int ans, T = -1;

bool bfs(void) {
    int cnt = 0;
    T++;  //시간계산
    q.push({ 0,0 });
    visited[0][0] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < M && !visited[nx][ny]) {
                visited[nx][ny] = true;        
                if (arr[nx][ny] == 0)         
                    q.push({ nx,ny });        
                else {        
                    arr[nx][ny] = 0;        
                    cnt++;  //사라진 치즈의 개수 저장, 사라질 치즈가 없는 경우 cnt=0        
                }        
            }
        }
    }
    //치즈가 모두 사라진 경우
    if (cnt == 0) {
        return true;
    }
    //치즈가 남아있는 경우
    else {
        //치즈가 모두 사라지기 전의 개수를 저장해야함
        ans = cnt;
        return false;
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
    while (1) {
        bool isEmpty = bfs();
        //치즈가 모두 사라진 경우
        if (isEmpty)
            break;
        //치즈가 남아있는 경우 방문 배열 초기화
        memset(visited, 0, sizeof(visited));
    }
    cout << T << endl << ans;
    return 0;
}