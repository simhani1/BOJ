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
#define INF 987654321
#define INIT 100000000
typedef long long ll;

int N;
int arr[51];

bool check(void)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += arr[i];
    if (sum == 0)
        return true;
    else
        return false;
}

int solve(void)
{
    int cnt = 0;
    while (true)
    {
        // 홀수 제거
        for (int i = 0; i < N; i++)
        {
            if (arr[i] % 2)
            {
                arr[i]--;
                cnt++;
            }
        }
        if (check())
            return cnt;
        for (int i = 0; i < N; i++)
            arr[i] /= 2;
        cnt++;
    }
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
    cout << solve() << "\n";
    return 0;
}
