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
int A, B, C;
int arr[501][501];
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
            cin >> arr[i][j];
        }
    }
    floyd();
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        //파티 오픈까지 걸리는 시간보다 파티장까지 도착하는 시간이 더 걸리면 도착 불가
        if (arr[A][B] > C)
            cout << "Stay here" << endl;
        else
            cout << "Enjoy other party" << endl;
    }
    return 0;
}