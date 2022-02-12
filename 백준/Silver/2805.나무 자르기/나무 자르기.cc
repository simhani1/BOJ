#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <time.h>

using namespace std;
typedef long long ll;
int N, M;
 ll arr[1000000];

ll binary_search(int left, int right) {
    ll result = 0;
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll sum = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i] > mid)
                sum += arr[i] - mid;
        }
        if (sum < M)
            right = mid - 1;
        else {
            result = max(result, mid);
            left = mid + 1;
        }
    }
    return result;
}

int main(void) {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    cout << binary_search(0, arr[N - 1]);
    return 0;
}