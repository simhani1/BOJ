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

int N;
int arr[501][501];
int dp[501][501];  //각 좌표에서 이동가능한 최대 칸수를 저장
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

int dfs(int x, int y) {
    //좌표에 대해서 dp값이 존재할 경우 바로 반환
    if (dp[x][y])
        return dp[x][y];
    else {
        //처음 방문했으므로 칸 수 증가
        dp[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                //다음 칸의 대나무 수가 더 많을 경우 이동
                if (arr[x][y] < arr[nx][ny]) {
                    //dfs함수를 실행시킬 경우 한칸 이동한것 이므로 1을 더해줘야 함
                    dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
                }
            }
        }
    }
    //이동할 수 없을 경우 그 칸의 dp값을 반환
    return dp[x][y];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans;
    return 0;
}