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
#define MAX 1000000007
typedef long long ll;

int N;
map<int, int> m;
vector<int> v;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (true)
    {
        cin >> N;
        if (N == 0)
            break;
        int idx = 0;
        for (int i = 0, X; i < N; i++)
        {
            cin >> X;
            if (i == 0)
            {
                v.push_back(X);
                idx++;
            }
            else
            {
                if (v[idx - 1] != X)
                {
                    v.push_back(X);
                    idx++;
                }
            }
        }
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << "$\n";
        m.clear();
        v.clear();
    }
    return 0;
}
