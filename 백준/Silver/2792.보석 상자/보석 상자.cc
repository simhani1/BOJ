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
ll arr[300000];
int M;

int main(void) {
    scanf("%lld %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%lld", &arr[i]);
    }
    sort(arr, arr + M);
    ll left = 1;
    ll right = arr[M - 1];
    while (left <= right) {
        ll sum = 0;
        //한 사람이 가져가는 보석 수
        ll mid = (left + right) / 2;
        //색깔별 보석들을 한 사람이 가져가는 보석 수로 나누고 모두 더하면 보석을 가져간 사람의 수와 같음
        for (int i = 0; i < M; i++) {
            if (!(arr[i] % mid))
                sum += arr[i] / mid;
            else
                sum += (arr[i] / mid) + 1;
        }
        if (sum > N)  //보석을 갖는 사람이 더 적으므로 한 사람이 갖는 보석 수를 감소시킨다
            left = mid + 1;
        else  //보석을 갖는 사람이 더 많으므로 한 사람이 갖는 보석 수를 증가시킨다
            right = mid - 1;
    }
    printf("%lld", left);
    return 0;
}