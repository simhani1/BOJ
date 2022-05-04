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
int menu, A, B;
int parent[1000001];

//부모 노드 찾기
int Find(int x)
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    int a = Find(x);
    int b = Find(y);
    //두 정수의 부모 노드가 다를 경우 부모 노드를 a로 설정
    if (a > b)
        parent[a] = b;
    else if (a < b)
        parent[b] = a;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //초기화
    cin >> N >> M;
    for (int i = 0; i <= N; i++)
    {
        parent[i] = i;
    }
    while (M--)
    {
        cin >> menu >> A >> B;
        //합치기
        if (menu == 0)
        {
            Union(A, B);
        }
        //집합에 포함돼 있는지 확인
        else
        {
            // A의 부모 노드와 B의 부모 노드가 같을 경우
            if (Find(A) == Find(B))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}