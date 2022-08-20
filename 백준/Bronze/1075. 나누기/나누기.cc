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

int N, F, idx;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> F;
    N = (N / 100) * 100;
    for (int i = 0, tmp; i < 100; i++)
    {
        tmp = N;
        idx = i;
        if ((tmp += i) % F == 0)
            break;
    }
    if (idx < 10)
        cout << 0;
    cout << idx;
    return 0;
}
