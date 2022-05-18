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

using namespace std;

int T;
int N, X, Y, R;
int ans;
int parent[3001];
vector<pair<int, pair<int, int> > > node;

int Find(int A)
{
    if (A == parent[A])
        return A;
    else
        return parent[A] = Find(parent[A]);
}

void Union(int A, int B)
{
    A = Find(A);
    B = Find(B);
    if (A != B)
        parent[B] = A;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        node.clear();
        cin >> N;
        ans = N;
        for (int i = 0; i < N; i++)
        {
            cin >> X >> Y >> R;
            node.push_back(make_pair(R, make_pair(X, Y)));
        }
        for (int i = 1; i <= N; i++)
        {
            parent[i] = i;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                int nowNode = i;
                int X1 = node[i].second.first;
                int Y1 = node[i].second.second;
                int R1 = node[i].first;

                int nextNode = j;
                int X2 = node[j].second.first;
                int Y2 = node[j].second.second;
                int R2 = node[j].first;

                if (Find(nowNode) == Find(nextNode))
                    continue;
                if (pow(X2 - X1, 2) + pow(Y2 - Y1, 2) <= pow(R1 + R2, 2))
                {
                    Union(nowNode, nextNode);
                    ans--;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}