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
    int C;
    int arr[1000];
    cin >> C;
    while (C--) {
        int n;
        cin >> n;
        int avg = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            avg += arr[i];
        }
        avg /= n;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > avg)
                cnt++;
        }
        cout << fixed;
        cout.precision(3);
        cout << (double)cnt / n * 100 << "%" << '\n';
        //하나의 값만 double형으로 변환시켜 다른 피연산자들이 묵시적 형변환
    }
    return 0;
}