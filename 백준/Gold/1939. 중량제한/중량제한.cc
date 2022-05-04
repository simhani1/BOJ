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
int A, B, C;
int S, E;
vector<pair<int, int> > node[10001];
int visited[10001];

bool BFS(int S, int std)
{
    queue<int> q;
    q.push(S);
    visited[S] = true;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        //마지막 섬까지 도달 가능하면 true 반환
        if (now == E)
            return true;
        else
        {
            for (int i = 0; i < node[now].size(); i++)
            {
                int nextNode = node[now][i].first;
                int nextCost = node[now][i].second;
                if (!visited[nextNode] && std <= nextCost)
                {
                    visited[nextNode] = true;
                    q.push(nextNode);
                }
            }
        }
    }
    //도달을 못하면 flase 반환
    return false;
}

void binary_search(int left, int right)
{
    while (left <= right)
    {
        //매번 방문 배열은 초기화 해주기
        for (int i = 1; i <= N; i++)
        {
            visited[i] = false;
        }
        visited[S] = true;
        int mid = (left + right) / 2;
        //물품이 모든 다리를 통과할 수 있는 경우
        //해당 무게를 기준으로 모든 다리를 다녀보고 도착점까지 도달 가능하면 기준 무게 증가시키기
        if (BFS(S, mid))
            left = mid + 1;
        else
            right = mid - 1;
    }
    cout << right;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    int maxWeight = 0;
    while (M--)
    {
        cin >> A >> B >> C;
        node[A].push_back(make_pair(B, C));
        node[B].push_back(make_pair(A, C));
        maxWeight = max(maxWeight, C);
    }
    cin >> S >> E;
    binary_search(0, maxWeight);
    return 0;
}