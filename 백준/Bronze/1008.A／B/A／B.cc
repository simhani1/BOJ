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
    double A, B;  //float: 4byte, double: 8byte
    //flaot: 8자리, double: 15자리까지 정확하게 나타냄
    cin >> A >> B;
    cout << fixed;  //소수점 이하 숫자만 다루도록 설정
    cout.precision(9);  //소수점 아래 9자리까지만 출력
    cout << A / B;
    return 0;
}