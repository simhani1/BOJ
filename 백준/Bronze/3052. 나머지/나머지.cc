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

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int arr[42] = { 0, };
    int n;
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        cin >> n;
        arr[n % 42] = 1;
    }
    for (int i = 0; i < 42; i++) {
        ans += arr[i];
    }
    cout << ans;
    return 0;
}