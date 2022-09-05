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

int N, X, pSum;
int arr[250001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> X;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= X; i++)
    {
        pSum += arr[i];
    }
    int ans = pSum, cnt = 1;
    for (int i = X + 1; i <= N; i++)
    {
        /**
         * if X == 3
         * pSum = pSum + arr[4] - arr[3]
         */
        pSum += (arr[i] - arr[i - X]);
        if (pSum > ans)
        {
            cnt = 1;
            ans = pSum;
        }
        else if (ans == pSum)
            cnt++;
    }
    if (!ans)
        cout << "SAD" << endl;
    else
        cout << ans << '\n'
             << cnt << endl;
    return 0;
}
