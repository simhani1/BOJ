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

int V, E;
int A, B, C;
int arr[401][401];
const int INF = 999999999;

void init(void) {
    cin >> V >> E;
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            arr[i][j] = INF;
        }
    }
    for (int i = 0; i < E; i++) {
        cin >> A >> B >> C;
        arr[A][B] = C;
    }
}

void floyd(void) {
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    floyd();
    int ans = INF;
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            //간선들 사이에서 사이클이 존재할 경우, 사이클 길이의 최소값을 저장
            ans = min(ans, arr[i][j] + arr[j][i]);
        }
    }
    if (ans == INF)
        cout << -1;
    else
        cout << ans;
    return 0;
}