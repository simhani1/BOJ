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
#define MOD 1000000007
#define INIT 100000000
typedef long long ll;

int N;
int arr[21];
bool visited[2000001];

void solve(int idx, int sum)
{
    if (idx == N)
    {
        visited[sum] = true;
        return;
    }
    solve(idx + 1, sum);
    solve(idx + 1, sum + arr[idx]);
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
    sort(arr, arr + N);
    solve(0, 0);
    int idx = 1;
    while (visited[idx])
        idx++;
    cout << idx << "\n";
    return 0;
}
