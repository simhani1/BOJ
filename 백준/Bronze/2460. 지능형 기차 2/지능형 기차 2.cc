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

int N, M, ans = 0;
int arr[10];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i < 10; i++)
    {
        cin >> N >> M;
        arr[i] = arr[i - 1];
        arr[i] -= N;
        arr[i] += M;
        ans = max(ans, arr[i]);
    }
    cout << ans;
    return 0;
}
