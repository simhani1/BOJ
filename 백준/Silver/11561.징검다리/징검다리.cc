#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
//등차수열의 합이 10^16가 되는 수
#define MAX 141421357

using namespace std;
typedef long long ll;

ll N;

int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &N);
        ll left = 1;
        ll right = MAX; 
        while (left <= right) {
            ll mid = (left + right) / 2;
            ll check = (mid * (mid + 1)) / 2;
            if (check == N) {
                right = mid;
                break;
            }
            else if (check > N)
                right = mid - 1;
            else
                left = mid + 1;
        }
        printf("%lld\n", right);
    }
    return 0;
}