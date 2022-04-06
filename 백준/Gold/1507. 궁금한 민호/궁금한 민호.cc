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
int arr[21][21];
int dist[21][21];
const int INF = 999999999;
bool flag = false;

void floyd(void) {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == k || k == j)
                    continue;
                if (arr[i][j] > arr[i][k] + arr[k][j]) {
                    flag = true;
                    return;
                }
                else if (arr[i][j] == arr[i][k] + arr[k][j])
                    dist[i][j] = 0;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            dist[i][j] = arr[i][j];
        }
    }
    floyd();
    int sum = 0;
    if (flag)
        cout << -1;
    else {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                sum += dist[i][j];
            }
        }
        cout << sum / 2;
    }
    return 0;
}