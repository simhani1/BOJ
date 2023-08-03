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
using namespace std;
#define INF 2000000000
typedef long long ll;

int N, H = 1;
int arr[500001], ans[500001];
vector<int> tree;
vector<pair<int, int>> v;

void update(int idx, int value)
{
    idx += (H - 1);
    tree[idx] = value;
    while (idx > 1)
    {
        idx /= 2;
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    }
}

int query(int L, int R, int node, int nodeL, int nodeR)
{
    if (L <= nodeL && nodeR <= R)
        return tree[node];
    if (nodeR < L || R < nodeL)
        return 0;
    int mid = (nodeL + nodeR) / 2;
    return query(L, R, 2 * node, nodeL, mid) + query(L, R, 2 * node + 1, mid + 1, nodeR);
}

void init(void)
{
    while (N > H)
    {
        H *= 2;
    }
    tree.resize(2 * H + 1);
}

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

void input(void)
{
    for (int i = 1, X; i <= N; i++)
    {
        cin >> X;
        v.push_back({X, i});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    { // 최대 10억인 실력을 최대 50만으로 표현할 수 있도록 압축
        v[i].first = i + 1;
    }
    sort(v.begin(), v.end(), comp); // 선수들의 인덱스로 기존 순서를 맞춰야 한다.
    // 여기까지 진행하면 학생들의 실력은 1 ~ N으로 표현되고 입력받은 학생들의 순서를 유지한 상태가 된다.
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    init();
    input();
    for (int i = 0; i < N; i++)
    {
        int talent = v[i].first;
        int idx = v[i].second;
        update(talent, 1);
        int result = query(1, talent - 1, 1, 1, H);
        if (result == 0 && i == 0)
        {
            ans[idx] = 1;
            continue;
        }
        ans[idx] = i + 1 - result;
    }
    for (int i = 1; i <= N; i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}
