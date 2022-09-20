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
#define INF 1e9
using namespace std;
typedef pair<int, int> pii;

int T, N, M, K;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        int dist[101][101];
        vector<int> person;
        cin >> N >> M;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (i == j)
                    dist[i][j] = 0;
                else
                    dist[i][j] = INF;
            }
        }
        for (int i = 0, A, B, C; i < M; i++)
        {
            cin >> A >> B >> C;
            dist[A][B] = C;
            dist[B][A] = C;
        }
        cin >> K;
        for (int i = 0, X; i < K; i++)
        {
            cin >> X;
            person.push_back(X);
        }
        for (int k = 1; k <= N; k++)
        {
            for (int i = 1; i <= N; i++)
            {
                for (int j = 1; j <= N; j++)
                {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        priority_queue<pii, vector<pii>, greater<pii>> ans;
        for (int i = 1; i <= N; i++)
        {
            int totalDist = 0;
            for (int j = 0; j < person.size(); j++)
            {
                totalDist += dist[i][person[j]];
            }
            ans.push({totalDist, i});
        }
        cout << ans.top().second << endl;
    }

    return 0;
}
