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
#define INF 123456789
#define INIT 100000000
typedef long long ll;

int N, M;
int dist[26][26];

void floydWarshall(void)
{
    for (int k = 0; k < 26; k++)
    {
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void init(void)
{
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    init();
    for (int i = 0; i < N; i++)
    {
        char X, Y;
        string Z;
        cin >> X >> Z >> Y;
        dist[X - 'a'][Y - 'a'] = 1;
    }
    floydWarshall();
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        char X, Y;
        string Z;
        cin >> X >> Z >> Y;
        if (dist[X - 'a'][Y - 'a'] == INF)
            cout << "F\n";
        else
            cout << "T\n";
    }
    return 0;
}
