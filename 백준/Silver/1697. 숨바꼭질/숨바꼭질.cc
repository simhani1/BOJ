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
#define MAX 123456789
typedef long long ll;

int N, K;
int arr[100001];
int dx[] = {-1, 1, 2};
bool visited[100001];

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        visited[now] = true;
        for (int i = 0; i < 3; i++)
        {
            int next;
            if (i == 2)
                next = now * dx[i];
            else
                next = now + dx[i];
            if (0 <= next && next <= 100000)
            {
                if (!visited[next])
                {
                    q.push(next);
                    arr[next] = min(arr[next], arr[now] + 1);
                }
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    fill(arr, arr + 100001, MAX);
    arr[N] = 0;
    bfs(N);
    cout << arr[K] << "\n";
    return 0;
}
