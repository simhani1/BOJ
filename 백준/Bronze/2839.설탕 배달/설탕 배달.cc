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

//그리디 알고리즘
int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;   
    int ans = 0;
    bool flag = false;
    cin >> N;
    while (N >= 0) {
        //제일 큰 수로 나누는게 best
        if (N % 5 == 0) {
            ans += N / 5;
            cout << ans;
            return 0;
        }
        N -= 3;
        ans++;
    }
    cout << -1;
    return 0;
}