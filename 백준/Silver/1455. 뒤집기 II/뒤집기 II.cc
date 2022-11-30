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
#define MAX 123456789
typedef long long ll;

int N, M;
int arr[101][101];

int solve(void)
{
    int ans = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = M - 1; j >= 0; j--)
        {
            if (arr[i][j] == 1)
            {
                ans++;
                for (int p = 0; p <= i; p++)
                {
                    for (int q = 0; q <= j; q++)
                    {
                        if (arr[p][q] == 1)
                            arr[p][q] = 0;
                        else
                            arr[p][q] = 1;
                    }
                }
            }
        }
    }
    return ans;
}

int main(void)
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1d", &arr[i][j]);
        }
    }
    cout << solve() << endl;
    return 0;
}
