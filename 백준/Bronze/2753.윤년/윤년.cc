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
    cin >> N;
     if (!(N % 4) && (N % 100) || !(N % 400))
        cout << 1;
    else
        cout << 0;
    return 0;
}