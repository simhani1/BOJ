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

int N, cnt = 0;
vector<pair<int, int>> v;
int arr[101], dp[101];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0, A, B; i < N; i++)
    {
        cin >> A >> B;
        v.push_back({A, B});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++)
    {
        arr[i] = v[i].second;
    }
    for (int i = 0; i < N; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        cnt = max(cnt, dp[i]);
    }
    cout << N - cnt << endl;
    return 0;
}
