#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <time.h>

using namespace std;

int main(void) {
    int N;
    int sum = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        sum += i;
    }
    cout << sum;
    return 0;
}