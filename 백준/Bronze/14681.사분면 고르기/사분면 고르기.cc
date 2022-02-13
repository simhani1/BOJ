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
    int x, y;
    cin >> x >> y;
    if (x > 0 && y > 0)
        cout << 1;
    else if (x < 0 && y>0)
        cout << 2;
    else if (x < 0 && y < 0)
        cout << 3;
    else
        cout << 4;
    return 0;
}