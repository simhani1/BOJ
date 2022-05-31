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

int N, A, B;
int X, Y;
vector<pair<int, int> > v;
set<pair<int, int> > pos;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> A >> B;
    for (int i = 0; i < N; i++)
    {
        cin >> X >> Y;
        v.push_back(make_pair(X, Y));
        pos.insert(make_pair(X, Y));
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int nowX = v[i].first;
        int nowY = v[i].second;
        if (pos.find({nowX + A, nowY}) == pos.end())
            continue;
        if (pos.find({nowX, nowY + B}) == pos.end())
            continue;
        if (pos.find({nowX + A, nowY + B}) == pos.end())
            continue;
        ans++;
    }
    cout << ans;
    return 0;
}