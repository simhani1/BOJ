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

int N;
int arr[200000];

int solve(void)
{
    int nowMin = 1234567890, nowMax = 0, diff = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] < nowMin)
        {
            nowMin = arr[i];
            nowMax = arr[i];
            continue;
        }
        else
        {
            nowMax = max(nowMax, arr[i]);
            diff = max(diff, nowMax - nowMin);
        }
    }
    return diff;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cout << solve() << endl;
    return 0;
}
