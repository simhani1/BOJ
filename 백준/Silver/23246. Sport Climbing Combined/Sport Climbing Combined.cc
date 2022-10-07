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

int N, B, P, Q, R;
vector<pair<pair<int, int>,int>> v;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> B >> P >> Q >> R;
        v.push_back({{P * Q * R, P+Q+R},B});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < 3; i++)
    {
        cout << v[i].second << " ";
    }
    return 0;
}
