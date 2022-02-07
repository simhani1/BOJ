#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;
typedef long long ll;

ll N;

int binary_search(void) {
    ll left = 0;
    ll right = sqrt(N);
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (mid < sqrt(N))
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int main(void) {
    scanf("%lld", &N);
    printf("%lld", binary_search());
    return 0;
}