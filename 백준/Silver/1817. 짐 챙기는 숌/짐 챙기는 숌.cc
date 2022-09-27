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

int N, M, ans = 0;
int arr[51];

int solve(void)
{
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        sum += arr[i];
        if (sum < M)
            continue;
        else if (sum == M)
        {
            ans++;
            sum = 0;
        }
        else
        {
            sum = 0;
            ans++;
            i--;
        }
    }
    if(sum!=0)
        ans++;
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    cout << solve() << endl;
    return 0;
}
