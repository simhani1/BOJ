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
int O, P, Q;
int parent[100001];
int army[100001];

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
    //두 나라가 동맹을 하면 병사가 합쳐진다.
    if (A > B)
    {
        parent[A] = B;
        army[B] += army[A];
        army[A] = 0;
    }
    else if (A < B)
    {
        parent[B] = A;
        army[A] += army[B];
        army[B] = 0;
    }
}

void Destruction(int A, int B)
{
    A = Find(A);
    B = Find(B);
    army[A] = 0;
    army[B] = 0;
    // A, B 두 나라와 동맹인 모든 나라가 멸망
    for (int i = 1; i <= N; i++)
    {
        if (parent[i] == A || parent[i] == B)
            parent[i] = 0;
    }
}

void Fight(int A, int B)
{
    A = Find(A);
    B = Find(B);
    //두 나라가 전댕을 하면 병사의 수가 줄어든다.
    if (army[A] < army[B])
    {
        parent[A] = B;
        army[B] -= army[A];
        army[A] = 0;
    }
    else if (army[A] > army[B])
    {
        parent[B] = A;
        army[A] -= army[B];
        army[B] = 0;
    }
    //병사의 수가 동일한 경우, 두 나라 모두 멸망
    else
        Destruction(A, B);
}

void initParent(void)
{
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
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> army[i];
    }
    initParent();
    for (int i = 0; i < M; i++)
    {
        cin >> O;
        cin >> P >> Q;
        if (O == 1)
            Union(P, Q);
        else if (O == 2)
            Fight(P, Q);
    }
    int ans = 0;
    sort(army, army + (N + 1));
    for (int i = 1; i <= N; i++)
    {
        //국가는 병사를 가지고 있어야 존재하는 법
        if (army[i])
            ans++;
    }
    cout << ans << endl;
    for (int i = 1; i <= N; i++)
    {
        if (army[i])
            cout << army[i] << " ";
    }
    return 0;
}