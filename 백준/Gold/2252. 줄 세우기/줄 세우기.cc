#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
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
int A, B;
vector <int> node[100000];
int indegree[32000];

void Input(void) {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        node[A].push_back(B);
        //들어오는 간선의 수를 저장
        indegree[B]++;
    }
}

void Solution(void) {
    queue <int> q;
    for (int i = 1; i <= N; i++) {
        //들어오는 간서의 수가 0인 노드의 경우 큐에 push
        if (!indegree[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cout << now << " ";
        for (int i = 0; i < node[now].size(); i++) {
            int next_node = node[now][i];
            indegree[next_node]--;
            if (!indegree[next_node])
                q.push(next_node);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Input();
    Solution();
    return 0;
}