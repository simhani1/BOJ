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

int N, L, R, X, ans = 0;
int arr[16];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> L >> R >> X;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < (1 << N); i++)
    {
        int maxScore = 0, minScore = 123456789, sum = 0, cnt = 0;
        for (int j = 0; j < N; j++)
        {
            if (i & (1 << j))
            {
                minScore = min(minScore, arr[j]);
                maxScore = max(maxScore, arr[j]);
                sum += arr[j];
                cnt++;
            }
        }
        if (cnt >= 2 && maxScore - minScore >= X && L <= sum && sum <= R)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
