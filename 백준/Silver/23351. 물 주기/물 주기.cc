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

int N, K, A, B;
int arr[101];

int solve(void)
{
    int date = 0;
    int start = 0, end = start + A;
    while (true)
    {
        for (int i = 0; i < N; i++)
        {
            if (start <= i && i < end)
                arr[i] += (B - 1);
            else
                arr[i]--;
        }
        if (end == N)
        {
            start = 0;
            end = A;
        }
        else
        {
            start += A;
            end += A;
        }
        date++;
        for (int i = 0; i < N; i++)
        {
            if (arr[i] == 0)
                return date;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K >> A >> B;
    for (int i = 0; i < N; i++)
    {
        arr[i] = K;
    }
    cout << solve() << "\n";
    return 0;
}
