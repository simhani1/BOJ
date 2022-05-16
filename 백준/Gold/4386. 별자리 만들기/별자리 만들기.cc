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

int N;
double X, Y;
vector<pair<double, double> > position;
priority_queue<pair<double, pair<int, int> > > pq;
int parent[101];

int Find(int A)
{
    if (A == parent[A])
        return A;
    else
        return parent[A] = Find(parent[A]);
}

void Union(int A, int B)
{
    A = parent[A];
    B = parent[B];
    if (A > B)
        parent[A] = B;
    else if (A < B)
        parent[B] = A;
}

//두 별 사이의 거리를 구해서 우선순위큐에 저장
void calcDist(double X, double Y, double P, double Q, int nowNode, int nextNode)
{
    double cost = sqrt(pow(P - X, 2) + pow(Q - Y, 2));
    pq.push(make_pair(-cost, make_pair(nowNode, nextNode)));
}

double Kruskal(void)
{
    double result = 0;
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
    //모든 별들 사이의 거리를 저장
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            calcDist(position[i].first, position[i].second, position[j].first, position[j].second, i + 1, j + 1);
        }
    }
    while (!pq.empty())
    {
        int nowNode = Find(pq.top().second.first);
        int nextNode = Find(pq.top().second.second);
        double cost = -pq.top().first;
        pq.pop();
        if (nowNode != nextNode)
        {
            Union(nowNode, nextNode);
            result += cost;
        }
    }
    return result;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    //별들의 좌표 입력
    for (int i = 0; i < N; i++)
    {
        cin >> X >> Y;
        position.push_back(make_pair(X, Y));
    }
    printf("%.2f", Kruskal());
    return 0;
}