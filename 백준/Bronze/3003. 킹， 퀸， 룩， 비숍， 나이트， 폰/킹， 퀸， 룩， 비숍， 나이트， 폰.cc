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
    int arr[6];
    int ans[6] = { 1,1,2,2,2,8 };
    for (int i = 0; i < 6; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < 6; i++) {
        arr[i] = ans[i] - arr[i];
    }
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}