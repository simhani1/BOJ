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
    int sum = 0;
    int A, B, C;
    cin >> A >> B >> C;
    int cnt = 1;
    bool flag = false;
    if (B >= C)
        cout << -1;
    else {
        cout << A / (C - B) + 1;
    }
    return 0;
}