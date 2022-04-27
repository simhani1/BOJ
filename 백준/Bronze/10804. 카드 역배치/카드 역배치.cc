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
#include <map>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int arr[20];
    int left, right, tmp;

    for (int i = 0; i < 20; i++) {
        arr[i] = i + 1;
    }
    for (int i = 0; i < 10; i++) {
        cin >> left >> right;
        while (left <= right) {
            tmp = arr[right - 1];
            arr[right - 1] = arr[left - 1];
            arr[left - 1] = tmp;
            left++;
            right--;
        }
    }
    for (int i = 0; i < 20; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}