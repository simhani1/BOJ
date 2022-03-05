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
    int n;
    for (int i = 0; i < 5; i++) {
        cin >> n;
        sum += n;
    }
    cout << sum;
    return 0;
}