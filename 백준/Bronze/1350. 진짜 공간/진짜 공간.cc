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

int N, cluster;
int arr[1001];
long long cnt = 0;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cin >> cluster;
    for (int i = 0; i < N; i++)
    {
        if (!(arr[i] % cluster))
            cnt += arr[i] / cluster;
        else
            cnt += arr[i] / cluster + 1;
    }
    cout << cnt * cluster;
    return 0;
}
