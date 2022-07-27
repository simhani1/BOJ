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
int arr[100001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    cin >> M;
    while (M--)
    {
        int L, R;
        cin >> L >> R;
        cout << arr[R] - arr[L - 1] << "\n";
    }
    return 0;
}
