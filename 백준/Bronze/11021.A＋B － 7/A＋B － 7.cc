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
    int T, A, B;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> A >> B;
        cout << "Case #" << i << ": " << A + B << '\n';
    }
    return 0;
}