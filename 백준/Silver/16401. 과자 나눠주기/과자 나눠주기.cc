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

int M, N;
int arr[1000000];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> M >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    int left = 1, right = arr[N - 1], ans = 0;
    while (left <= right)
    {
        int cnt = 0;
        int mid = (left + right) / 2;
        for (auto i : arr)
        {
            cnt += (i / mid);
        }
        // 나눠주는 길이가 길어질수록 cnt는 줄어든다
        if (cnt >= M)
        {
            ans = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    cout << ans;
    return 0;
}