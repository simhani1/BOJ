#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define INF 1234567890
typedef long long ll;

int N;
int arr[3], maxSum[3], minSum[3];

void printAns(void)
{
    int maxAns = 0, minAns = INF;
    for (int i = 0; i < 3; i++)
    {
        maxAns = max(maxAns, maxSum[i]);
        minAns = min(minAns, minSum[i]);
    }
    cout << maxAns << " " << minAns << "\n";
}

void init(void)
{
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
        maxSum[i] = arr[i];
        minSum[i] = arr[i];
    }
}

void solve(void)
{
    cin >> N;
    init();
    for (int k = 1; k < N; k++)
    {
        for (int i = 0; i < 3; i++)
        {
            cin >> arr[i];
        }
        int tmp0 = maxSum[0], tmp1 = maxSum[1];
        maxSum[0] = max(maxSum[0], maxSum[1]) + arr[0];
        maxSum[1] = max(tmp0, max(maxSum[1], maxSum[2])) + arr[1];
        maxSum[2] = max(tmp1, maxSum[2]) + arr[2];

        tmp0 = minSum[0], tmp1 = minSum[1];
        minSum[0] = min(minSum[0], minSum[1]) + arr[0];
        minSum[1] = min(tmp0, min(minSum[1], minSum[2])) + arr[1];
        minSum[2] = min(tmp1, minSum[2]) + arr[2];
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    printAns();
    return 0;
}
