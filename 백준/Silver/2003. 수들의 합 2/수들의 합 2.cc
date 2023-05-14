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
#define INF 123456789
typedef long long ll;

int N, M;
int arr[10001];

int solve(void)
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = i; j < N; j++)
        {
            sum += arr[j];
            if (sum == M)
                cnt++;
        }
    }
    return cnt;
}

void input(void)
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    cout << solve() << "\n";
    return 0;
}
