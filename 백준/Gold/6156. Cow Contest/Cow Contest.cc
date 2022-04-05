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
int A, B;
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
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        arr[A][B] = 1;
    }
    floyd();
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        for (int j = 1; j <= N; j++) {
            if (i == j)
                continue;
            //내 능력치 기준으로 앞뒤에 소가 있다면 상대적인 순위를 알 수 있는 가능성이 있음
            if (arr[i][j] != INF || arr[j][i] != INF)
                cnt++;
        }
        //나보다 높은 능력치를 가진 소의 수와 낮은 능력치를 가진 소의 수 합이 N -1 과 같다면 등수를 알 수 있음
        if (cnt == N - 1)
            ans++;
    }
    cout << ans;
    return 0;
}