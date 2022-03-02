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
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    int p = 0, q = 0, r = w, s = h;
    int ans1 = 9999, ans2 = 9999;
    int ans;
    ans = min(min(abs(x - p), abs(x - r)), min(abs(y - q), abs(y - s)));
    cout << ans;
    return 0;
}