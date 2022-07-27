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

int N, M;
int arr[15001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    int cnt = 0;
    sort(arr, arr + N);
    for (int i = 1; i < N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            if (arr[i] + arr[j] == M)
                cnt++;
        }
    }
    cout << cnt;
    return 0;
}
