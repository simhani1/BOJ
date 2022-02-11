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
ll arr[100000];

ll binary_search(ll left, ll right) {
    ll ans = 0;
    while (left <= right) {
        ll cnt = 0;
        ll mid = (left + right) / 2;
        for (int i = 0; i < N; i++) {
            cnt += mid / arr[i];  //상담소에서 처리 가능한 인원수의 총 합
        }
        if (cnt < M)  //처리 인원이 적으므로 상담 시간 늘려야 함
            left = mid + 1;
        else {  //처리 인원이 더 많으므로 상담 시간 줄여야 함
            ans = mid;
            right = mid - 1;
        }
    }
    return ans;
}

int main(void) {
    cin >> N >> M;
    ll max_time = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        max_time = max(max_time, arr[i]);
    }
    cout << binary_search(1, max_time * M);
    return 0;
}
