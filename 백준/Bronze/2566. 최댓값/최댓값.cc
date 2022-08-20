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
vector<pair<int, pair<int, int>>> v;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ans = 0;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            int N;
            cin >> N;
            v.push_back({N, {i, j}});
        }
    }
    sort(v.begin(), v.end(), greater<pair<int, pair<int, int>>>());
    cout << v[0].first << "\n"
         << v[0].second.first << " " << v[0].second.second;
    return 0;
}
