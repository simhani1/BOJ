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

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    int cnt = 0;
    cin >> N;
    while (N >= 0)
    {
        if (!(N % 5))
        {
            cout << N / 5 + cnt << endl;
            return 0;
        }
        else
        {
            cnt++;
            N -= 2;
        }
    }
    cout << -1 << endl;
    return 0;
}