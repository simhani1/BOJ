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

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int ans;
    switch (N % 8)
    {
    case 1:
    {
        ans = 1;
        break;
    }
    case 0:
    case 2:
    {
        ans = 2;
        break;
    }
    case 3:
    case 7:
    {
        ans = 3;
        break;
    }
    case 4:
    case 6:
    {
        ans = 4;
        break;
    }
    case 5:
    {
        ans = 5;
        break;
    }
    }
    cout << ans;
    return 0;
}
