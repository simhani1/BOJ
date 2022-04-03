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
int U, V, W;
int arr[101][101];
const int INF = 999999999;

void floyd(void) {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i != j)
                arr[i][j] = INF;
        }
    }
    //노선과 거리 저장
    for (int i = 0; i < M; i++) {
        cin >> U >> V >> W;
        //같은 노선에 비용이 다르게 입력이 되는 경우가 존재하므로 최소 비용만 저장
        arr[U][V] = min(arr[U][V], W);
    }
    floyd();
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (arr[i][j] != INF)
                cout << arr[i][j] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}