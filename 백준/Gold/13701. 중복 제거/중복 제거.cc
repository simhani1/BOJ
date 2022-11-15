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

int N, arr[(1 << 20) + 2];

/**
 int 타입으로 32bit를 저장할 수 있으므로
 arr[0] -> 1*32까지 표현 가능
 arr[1] -> 2*32까지 표현 가능
 2^25를 32로 나누면 대략 2^20이 된다.
 */

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> N)
    {
        int idx = N / 32;
        int shift = N % 32;
        if (arr[idx] & (1 << shift))
            continue;
        cout << N << " ";
        arr[idx] += (1 << shift);
    }
    return 0;
}
