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

bool prime_num(int n) {
    int cnt = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (!(n % i))
            cnt++;
    }
    if (cnt == 1)
        return 1;
    else return 0;
}
int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int M, N;
    int sum = 0;
    int min_num = 99999;
    cin >> M >> N;
    for (int i = M; i <= N; i++) {
        if (prime_num(i)) {
            sum += i;
            min_num = min(min_num, i);
        }
    }
    if (min_num < 99999)
        cout << sum << endl << min_num;
    else
        cout << -1;
    return 0;
}
