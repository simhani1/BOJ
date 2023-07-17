#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define INF 2000000000
typedef long long ll;

int N, M;
int parent[100001];
vector<pair<int, pair<int, int>>> v;

int Find(int A)
{
    if (A == parent[A])
        return A;
    return parent[A] = Find(parent[A]);
}

void Union(int A, int B)
{
    A = Find(A);
    B = Find(B);
    parent[max(A, B)] = min(A, B);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
    for (int i = 0, U, V, T; i < M; i++)
    {
        cin >> U >> V >> T;
        v.push_back({T, {U, V}});
    }
    sort(v.begin(), v.end());
    bool flag = true;
    int cnt = 1, target;
    for (int i = 0; i < v.size(); i++)
    {
        if (cnt == N)
            break;
        int time = v[i].first;
        int U = v[i].second.first;
        int V = v[i].second.second;
        if (time != cnt)
            break;
        // 모든 요리 학원에 다닐 수 있도록 N-1개의 경로를 고르고 키위새가 쓰러지는 날을 출력
        // 즉 무조건 N-1개의 경로를 선택하는 것이 아니고 N-1개 정점이 모두 이어지도록 연결해야 한다.
        if (Find(U) != Find(V))
        {
            Union(U, V);
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
