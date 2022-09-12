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

long long N;
int arr[100001];
bool visited[100001];

long long solve(void)
{
    long long l = 0, r = 0;
    long long ans = N * (N + 1) / 2;
    while (r < N)
    {
        while (!visited[arr[r]] && r < N)
        {
            visited[arr[r]] = true;
            r++;
        }
        ans -= (N - r);
        visited[arr[l]] = false;
        l++;
    }
    return ans;
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
    cout << solve() << endl;
    return 0;
}
