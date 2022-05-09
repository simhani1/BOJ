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

int T, N;
int I, J;
char menu;
int parent[20001];
int dist[20001];

int Find(int A)
{
    if (parent[A] == A)
        return A;
    //부모 노드까지의 거리를 구하기 위해 부모 노드를 찾는 코드가 먼저 실행된다
    int tmp_parent = Find(parent[A]);
    //길이 누적합 저장
    dist[A] += dist[parent[A]];
    return parent[A] = tmp_parent;
}

void Union(int A, int B)
{
    //입력되는 순서대로 부노 자식 관계가 된다
    dist[A] = abs(A - B) % 1000;
    parent[A] = B;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> N;
        for (int i = 1; i <= N; i++)
        {
            parent[i] = i;
            dist[i] = 0;
        }
        while (true)
        {
            cin >> menu;
            if (menu == 'O')
                break;
            else if (menu == 'E')
            {
                cin >> I;
                Find(I);
                //부모 노드까지의 길이 출력하기
                cout << dist[I] << "\n";
            }
            else if (menu == 'I')
            {
                cin >> I >> J;
                Union(I, J);
            }
        }
    }
    return 0;
}