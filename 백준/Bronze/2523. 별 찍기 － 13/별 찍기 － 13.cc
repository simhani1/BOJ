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
    for (int i = 1; i <= 2 * N - 1; i++) {
        for (int j = 0; j < N - (abs((N - i)) % N); j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}