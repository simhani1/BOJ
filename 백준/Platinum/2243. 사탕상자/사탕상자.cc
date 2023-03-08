#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;
#define INF 2147483648
typedef long long ll;

int N;
vector<int> tree;

int sum(int idx)
{
    int result = 0;
    while (idx > 0)
    {
        result += tree[idx];
        idx -= (idx & -idx);
    }
    return result;
}

void update(int idx, int cnt)
{
    while (idx < tree.size())
    {
        tree[idx] += cnt;
        idx += (idx & -idx);
    }
}

int select(int rank)
{
    int l = 1, r = 1000000;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (sum(mid) >= rank)
            r = mid - 1;
        else
            l = mid + 1;
    }
    update(l, -1);
    return l;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    tree.resize(1000001);
    for (int i = 0, A, B, C; i < N; i++)
    {
        cin >> A;
        if (A == 1)
        {
            cin >> B;
            cout << select(B) << "\n";
        }
        else
        {
            cin >> B >> C;
            update(B, C);
        }
    }
    return 0;
}
