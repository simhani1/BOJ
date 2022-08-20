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
int cnt = 1, sum = 0;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0, M; i < N; i++)
    {
        cin >> M;
        if (M == 1)
        {
            sum += cnt;
            cnt++;
        }
        else
            cnt = 1;
    }
    cout << sum;
    return 0;
}
