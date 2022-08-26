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

int N, X;
int arr[1000001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cin >> X;
    sort(arr, arr + N);
    int left = 0, right = N - 1, ans = 0;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == X)
        {
            left++;
            right--;
            ans++;
        }
        else if (sum < X)
            left++;
        else
            right--;
    }
    cout << ans;
    return 0;
}