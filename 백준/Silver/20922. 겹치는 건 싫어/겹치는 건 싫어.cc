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

int N, K;
int arr[200001];
map<int, int> m;

int solve(void)
{
    int l = 0, r = 0, ans = 0;
    while (l != N && r != N)
    {
        if (m[arr[r]] == K)
        {
            m[arr[l]]--;
            l++;
        }
        else
        {
            m[arr[r]]++;
            ans = max(ans, r - l + 1);
            r++;
        }
    }
    return ans;
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
    }
    cout << solve() << endl;
    return 0;
}
