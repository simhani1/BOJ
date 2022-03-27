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
    int sum = 0;
    int ans = 9999;
    for (int i = 0; i < 7; i++) {
        cin >> N;
        //홀수일 경우
        if (N % 2) {
            ans = min(ans, N);
            sum += N;
        }
    }
    if (ans == 9999)
        cout << -1;
    else
        cout << sum << endl << ans;
    return 0;
}