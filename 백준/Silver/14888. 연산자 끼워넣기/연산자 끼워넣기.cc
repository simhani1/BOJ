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
#define INF 1234567890
typedef long long ll;

int N;
vector<int> v;
int arr[4], maxAns = INF * -1, minAns = INF;

void solve(int idx, int result)
{
    if (idx == N)
    {
        maxAns = max(maxAns, result);
        minAns = min(minAns, result);
        return;
    }
    int A = result;
    int B = v[idx];
    int tmp;
    for (int i = 0; i < 4; i++)
    {
        if (arr[i])
        {
            if (i == 0)
                tmp = A + B;
            else if (i == 1)
                tmp = A - B;
            else if (i == 2)
                tmp = A * B;
            else
                tmp = A / B;
            arr[i]--;
            solve(idx + 1, tmp);
            arr[i]++;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0, X; i < N; i++)
    {
        cin >> X;
        v.push_back(X);
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> arr[i];
    }
    solve(1, v[0]);
    cout << maxAns << "\n"
         << minAns << "\n";
    return 0;
}
