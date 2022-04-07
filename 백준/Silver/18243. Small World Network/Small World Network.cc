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

int N, K;
int A, B;
int arr[101][101];
const int INF = 999999999;

void init(void) {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i != j)
                arr[i][j] = INF;
        }
    }
    for (int i = 0; i < K; i++) {
        cin >> A >> B;
        arr[A][B] = 1;
        arr[B][A] = 1;
    }
}

void floyd(void) {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
}

void solve(void) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i != j) {
                if (arr[i][j] > 6) {
                    cout << "Big World!";
                    return;
                }
            }
        }
    }
    cout << "Small World!";
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    floyd();
    solve();
    return 0;
}