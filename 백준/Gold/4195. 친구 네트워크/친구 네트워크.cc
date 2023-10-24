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
#define INF 123456789
#define MOD 987654321
typedef long long ll;

int T, F;
int parent[200001];
int freindCnt[200001];
map<string, int> m;

int Find(int a)
{
    if (a == parent[a])
        return a;
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    // 부모가 다른 경우 친구를 합해야 한다
    if (a != b)
    {
        parent[max(a, b)] = min(a, b);
        freindCnt[min(a, b)] += freindCnt[max(a, b)];
    }
}

void init(void)
{
    for (int i = 0; i < 200001; i++)
    {
        parent[i] = i;
        freindCnt[i] = 1;
    }
}

void input(void)
{
    cin >> T;
    while (T--)
    {
        cin >> F;
        int num = 0, a, b;
        init();
        for (int i = 0; i < F; i++)
        {
            string A, B;
            cin >> A >> B;
            if (m.find(A) == m.end())
                m[A] = num++;
            a = m[A];
            if (m.find(B) == m.end())
                m[B] = num++;
            b = m[B];
            Union(a, b);
            cout << freindCnt[Find(min(a, b))] << "\n";
        }
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
