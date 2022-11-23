#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <time.h>
#include <map>
#include <set>
using namespace std;

double A, D, K;
double sum = 0;
int cnt = 0;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> D >> K;
    double tmp = A;
    while (D < 100.0)
    {
        sum += (A * (1 - D / 100));
        A *= (1 - D / 100);
        D *= (1 + K / 100);
    }
    printf("%.6lf", sum + tmp);
    return 0;
}
