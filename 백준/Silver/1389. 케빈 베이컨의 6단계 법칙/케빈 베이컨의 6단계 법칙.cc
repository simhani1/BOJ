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
int U, V;
int arr[101][101];
vector <pair<int, int >> kevinBaconNum;
const int INF = 99999;

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
    //모든 간선의 가중치는 1
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i != j)
                arr[i][j] = INF;
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> U >> V;
        arr[U][V] = 1;
        arr[V][U] = 1;
    }
    floyd();
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= N; j++) {
            sum += arr[i][j];
        }
        //케빈 베이컨 수와 사람 번호를 저장
        kevinBaconNum.push_back({ sum, i });
    }
    //케빈 베이컨 수를 기준으로 오름차순 정렬
    sort(kevinBaconNum.begin(), kevinBaconNum.end());
    cout << kevinBaconNum[0].second;
    return 0;
}