#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;
typedef long long ll;

int K, N;
ll arr[10000];

ll binary_search(ll left, ll right) {    
    ll ans = 0;
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll cnt = 0;
        for (int i = 0; i < K; i++) {
            cnt += (arr[i] / mid);
        }
        if (cnt >= N) {
            ans = max(ans, mid);
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return ans;
}

int main(void) {
    scanf("%d %d", &K, &N);
    for (int i = 0; i < K; i++) {
        scanf("%lld", &arr[i]);
    }
    sort(arr, arr + K);
    printf("%lld", binary_search(1, arr[K - 1]));
    return 0;
}
