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
int arr[367];

int solve(void)
{
    for (int i = 1; i <= 366; i++)
        arr[i] += arr[i - 1];
    int len = 0, h = 0, sum = 0;
    for (int i = 1; i <= 366; i++)
    {
        if (arr[i] == 0 || i == 366)
        {
            sum += (len * h);
            len = 0;
            h = 0;
        }
        else
        {
            len++;
            h = max(h, arr[i]);
        }
    }
    return sum;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0, A, B; i < N; i++)
    {
        cin >> A >> B;
        arr[A]++;
        arr[B + 1]--;
    }
    cout << solve() << "\n";
    return 0;
}
