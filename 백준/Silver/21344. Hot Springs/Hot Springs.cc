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

int N;
int arr[100001];
vector<int> ans;

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
    if (N % 2)
    {
        for (int i = 0; i <= N / 2; i++)
        {
            if (i == N - 1 - i)
                ans.push_back(arr[i]);
            else
            {
                ans.push_back(arr[i]);
                ans.push_back(arr[N - 1 - i]);
            }
        }
    }
    else
    {
        for (int i = 0; i < N / 2; i++)
        {
            ans.push_back(arr[i]);
            ans.push_back(arr[N - 1 - i]);
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
