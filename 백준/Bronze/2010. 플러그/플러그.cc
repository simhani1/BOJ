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

int N, M;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> M;
        if (i != N)
            ans += (M - 1);
        else
            ans += M;
    }
    cout << ans;
    return 0;
}