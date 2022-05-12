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
int arr[1001];
int X;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> X;
        arr[X]++;
    }
    int ans = 0;
    for (int i = 1; i <= M; i++)
    {
        ans = max(ans, arr[i]);
    }
    cout << ans;
    return 0;
}