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
int pos[100001], arr[100001];
vector<int> lis;

void solve(void)
{
    lis.push_back(arr[0]);
    for (int i = 1; i < N; i++)
    {
        int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
        if (idx == lis.size())
            lis.push_back(arr[i]);
        else
            lis[idx] = arr[i];
    }
    cout << lis.size() << "\n";
}

void input(void)
{
    cin >> N;
    for (int i = 0, X; i < N; i++)
    {
        cin >> X;
        pos[X] = i;
    }
    for (int i = 0, X; i < N; i++)
    {
        cin >> X;
        arr[i] = pos[X];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}
