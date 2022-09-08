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
#define MAX 1e9

int N, K;
int arr[10001], count1[10001], count2[10001];
set<int> s1, s2;

void solve(void)
{
    int l = 0, r = 0, ans = MAX;
    while (r <= N && l <= N)
    {
        if (s1.size() >= s2.size())
        {
            if (s1.size() == K && s2.size() == K)
                ans = min(ans, r - l + 1);
            count1[arr[l]]--;
            count2[arr[l]]++;
            if (count1[arr[l]] == 0)
                s1.erase(arr[l]);
            if (l != N)
                s2.insert(arr[l]);
            l++;
        }
        else
        {
            r++;
            count1[arr[r]]++;
            count2[arr[r]]--;
            if (count2[arr[r]] == 0)
                s2.erase(arr[r]);
            if (r != N)
                s1.insert(arr[r]);
        }
    }
    if (ans == MAX)
        ans = 0;
    cout << ans << endl;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if (i == 0)
        {
            s1.insert(arr[i]);
            count1[arr[i]]++;
        }
        else
        {
            s2.insert(arr[i]);
            count2[arr[i]]++;
        }
    }
    solve();
    return 0;
}
