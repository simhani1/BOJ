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

char arr[100][101];
bool visited[100][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int N;

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < N && 0 <= ny && ny < N) {
            if (!visited[nx][ny] && arr[nx][ny] == arr[x][y]) {
                dfs(nx, ny);
            }
        }
    }
}

int main(void) {
    cin >> N;
    for(int i=0;i<N;i++){
        scanf("%s", arr[i]);
    }  
    int cnt_normal = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                dfs(i, j);
                cnt_normal++;
            }
        }
    }
    //적록색약의 시각으로 변경
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 'R') 
                arr[i][j] = 'G';
            visited[i][j] = false;
        }
    }
    int cnt_weakness = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                dfs(i, j);
                cnt_weakness++;
            }
        }
    }
    cout << cnt_normal << " " << cnt_weakness;
    return 0;
}