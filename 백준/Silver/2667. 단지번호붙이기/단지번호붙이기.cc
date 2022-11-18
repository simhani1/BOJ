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

int N;
int arr[25][25];
bool visited[25][25];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
vector <int> cnt_home;
int ans = 0;

void dfs(int p, int q) {
    visited[p][q] = true;
    for (int i = 0; i < 4; i++) {
        int np = p + dx[i];
        int nq = q + dy[i];
        if (0 <= np && np < N && 0 <= nq && nq < N) {
            if (!visited[np][nq] && arr[np][nq] == 1) {
                ans++;
                dfs(np, nq);
            }
        }
    }   
}

int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    int cnt_block = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans = 0;
            if (arr[i][j] == 1 && !visited[i][j]) {
                ans++;
                dfs(i, j);
                cnt_home.push_back(ans);
                cnt_block++;
            }
        }
    }
    sort(cnt_home.begin(), cnt_home.end());
    cout << cnt_block << endl;
    for (int i = 0; i < cnt_home.size(); i++) {
        cout << cnt_home[i] << endl;
    }
    return 0;
}