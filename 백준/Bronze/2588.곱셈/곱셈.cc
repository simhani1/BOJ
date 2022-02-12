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
    int A, B;
    int arr[3];
    cin >> A >> B;
    for (int i = 0; i < 3; i++) {
        arr[i] = (B % 10) * A;
        B /= 10;
    }
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << endl;
        sum += (arr[i] * pow(10, i));
    }
    cout << sum << endl;
    return 0;
}