#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
using namespace std;
#define INF 2000000000
#define MOD 1000000
typedef long long ll;

int N;
int arr[100001];
vector<int> lis;

void solve(void)
{
    lis.push_back(arr[0]);
    int i = 1, j = 0;
    while (i < N)
    {
        if (lis.back() < arr[i])
            lis.push_back(arr[i]);
        else
        {
            auto idx = lower_bound(lis.begin(), lis.end(), arr[i]);
            *idx = arr[i];
        }
        i++;
    }
    cout << lis.size() << "\n";
}

void init(void)
{
    fill(arr, arr + 100001, 0);
    lis.clear();
}

void input(void)
{
    while (cin >> N)
    {
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        solve();
        init();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    return 0;
}
