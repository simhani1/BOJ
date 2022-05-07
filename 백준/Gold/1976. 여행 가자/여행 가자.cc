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

int N, M;
int arr[201][201];
bool check[201][201];
int parent[201];
int plan[1001];

int Find(int A)
{
    if (parent[A] == A)
        return A;
    return parent[A] = Find(parent[A]);
}

void Union(int A, int B)
{
    A = Find(A);
    B = Find(B);
    if (A > B)
        parent[A] = B;
    else if (A < B)
        parent[B] = A;
}

void solve(void)
{
    bool isOk = true;
    for (int i = 1; i < M; i++)
    {
        if (parent[plan[i]] != parent[plan[i + 1]])
        {
            isOk = false;
            break;
        }
    }
    if (isOk)
        cout << "YES";
    else
        cout << "NO";
}

void find_parent(void)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (arr[i][j] && (parent[i] != parent[j]))
            {
                Union(i, j);
            }
        }
    }
}

void init(void)
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> plan[i];
    }
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    find_parent();
    solve();
    return 0;
}