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
#include <map>

using namespace std;

int M, N, ans;
int num[2001][2001];
int print[2001][2001];
int store[2001][2001];

void robot(void) {
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= M; i++) {
            for (int k = -1; k <= 1; k++) {
                store[i][j] = max(store[i][j], print[i + k][j - 1]);
            }
            print[i][j] = store[i][j] + num[i][j];
            // 저장된 값 중 최댓값
            ans = max(ans, store[i][j]);
        }
    }
    cout << ans;
}

int main(void) {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    cin >> M >> N;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%1d", &num[i][j]);
        }
    }
    robot();
    return 0;
}