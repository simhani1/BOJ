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
#include <cmath>
using namespace std;
#define INF 1e15
#define MOD 1000000
typedef long long ll;

int N, M;
vector<pair<pair<int, int>, int>> v;
bool removedLine[500001];

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    if (a.first.first == b.first.first)
        return a.first.second > b.first.second;
    return a.first.first < b.first.first;
}

void solve()
{
    sort(v.begin(), v.end(), compare);
    int l = v[0].first.first, r = v[0].first.second;
    for (int i = 1; i < v.size(); i++)
    {
        int targetL = v[i].first.first, targetR = v[i].first.second, line = v[i].second;
        // 이미 제거된 노선인 경우
        if (removedLine[line])
            continue;
        // 현재 노선이 다른 노선에 포함되는 경우
        if (l <= targetL && targetR <= r)
        {
            removedLine[line] = true;
            continue;
        }
        l = targetL;
        r = targetR;
    }
    for (int i = 1; i <= M; i++)
    {
        if (!removedLine[i])
            cout << i << " ";
    }
}

void input()
{
    cin >> N >> M;
    for (int i = 1, A, B; i <= M; i++)
    {
        cin >> A >> B;
        if (A < B)
        {
            v.push_back({{A, B}, i});
            v.push_back({{A + N, B + N}, i});
        }
        else
            v.push_back({{A, B + N}, i});
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
