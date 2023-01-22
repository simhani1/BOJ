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

double X, Y; // 승률 계산에서 정수로 계산하면 오차가 발생
int Z;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> X >> Y;
    Z = floor(Y * 100 / X);
    int left = 1, right = 1000000000, cnt = -1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int tmp = floor((Y + mid) * 100 / (X + mid));
        if (tmp > Z)
        {
            cnt = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    cout << cnt;
    return 0;
}