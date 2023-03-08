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

int N, K;
vector<int> tree;
int arr[250001];

ll sum(int idx)
{
    idx++;
    ll result = 0;
    while (idx > 0)
    {
        result += tree[idx];
        idx -= (idx & -idx);
    }
    return result;
}

int findMid()
{
    int l = 0, r = 65536;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (sum(mid) >= ((K + 1) / 2))
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}

void update(int idx, int value)
{
    // 펜윅트리에서 첫번째 인덱스로 1을 사용해야 한다.
    // 현재 문에서는 0자체가 인덱스로 사용이 되므로 tree[1]에 0의 개수를 저장하는 식으로 해야한다.
    idx++;
    while (idx < tree.size())
    {
        tree[idx] += value;
        idx += (idx & -idx);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    tree.resize(65538);
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    ll ans = 0;
    for (int i = 1; i <= K; i++)
    {
        update(arr[i], 1);
    }
    ans += findMid();
    for (int i = K + 1; i <= N; i++)
    {
        update(arr[i - K], -1);
        update(arr[i], 1);
        ans += findMid();
    }
    cout << ans << "\n";
    return 0;
}
