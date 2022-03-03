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

int arr[101];

void change_ball(int i, int j) {
    int tmp;
    tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M;
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        arr[i] = i;
    }
    while (M--) {
        int i, j;
        cin >> i >> j;
        change_ball(i, j);
    }
    for (int i = 1; i <= N; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}