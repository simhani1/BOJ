#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <time.h>
#include <map>

using namespace std;

double x[10000], y[10000];

//외적으로 면적 구하기
double  cross_product(int p, int q, int r) {
    double plus = x[p] * y[q] + x[q] * y[r] + x[r] * y[p];
    double minus = x[q] * y[p] + x[r] * y[q] + x[p] * y[r];
    return (plus - minus) / 2;
}

int main(void) {
    int N;
    double ans = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i < N - 1; i++) {
        ans += cross_product(0, i, i + 1);
    }
    printf("%.1f", abs(ans));
    return 0;
}