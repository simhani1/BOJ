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
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int A, B;
    while (true) {
        cin >> A >> B;
        if (A == 0 && B == 0)
            break;
        cout << A + B << '\n';
    }
    return 0;
}