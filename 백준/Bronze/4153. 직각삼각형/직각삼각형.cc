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
    //https://www.acmicpc.net/problem/1743
    int arr[3];
    while (1) {
        for (int i = 0; i < 3; i++) {
            cin >> arr[i];
        }
        if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
            break;
        sort(arr, arr + 3, greater<int>());
        if (arr[0] * arr[0] == arr[1] * arr[1] + arr[2] * arr[2])
            cout << "right" << endl;
        else
            cout << "wrong" << endl;
    }
    return 0;
}