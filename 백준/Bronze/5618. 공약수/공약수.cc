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

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    int arr[3];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    if (N == 2) {
        for (int i = 1; i <= arr[N - 1]; i++) {
            if (arr[0] % i == 0 && arr[1] % i == 0)
                cout << i << endl;
        }
    }
    if (N == 3) {
        for (int i = 1; i <= arr[N - 1]; i++) {
            if (arr[0] % i == 0 && arr[1] % i == 0 && arr[2] % i == 0)
                cout << i << endl;
        }
    }
    return 0;
}