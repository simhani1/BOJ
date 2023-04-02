#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;
#define INF 123456789
typedef long long ll;

int N;
int arr[1000001];
int lis[1000001];

int binarySearch(int l, int r, int find)
{
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (lis[mid] < find)
            l = mid + 1;
        else
            r = mid;
    }
    return r;
}

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
    int i = 1, j = 0;
    lis[0] = arr[0];
    while (i < N)
    {
        if (lis[j] < arr[i])
            lis[++j] = arr[i];
        else
        {
            int idx = binarySearch(0, j, arr[i]);
            lis[idx] = arr[i];
        }
        i++;
    }
    cout << j + 1 << endl;
    return 0;
}
