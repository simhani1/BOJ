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
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < N - i; j++)
            cout << ' ';
        for (int j = 0; j < 2 * i - 1; j++)
            cout << '*';
        cout << endl;
    }
    for (int i = N - 1; i >= 1; i--) {
        for (int j = 0; j < N - i; j++)
            cout << ' ';
        for (int j = 0; j < 2 * i - 1; j++)
            cout << '*';
        cout << endl;
    }
    return 0;
}