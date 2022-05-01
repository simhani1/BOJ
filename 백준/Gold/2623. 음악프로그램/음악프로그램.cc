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
vector <int> node[1001];
vector <int> ans;
int indegree[1001];

void Input(void) {
    int num, A, B;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> num;
        //맡은 가수가 없을 수도 있다.
        if (num != 0) {
            cin >> A;
            for (int j = 0; j < num - 1; j++) {
                cin >> B;
                node[A].push_back(B);
                indegree[B]++;
                A = B;  //현재 가수의 다음에 오는 가수를 저장해야 한다
            }
        }
    }
}

void Solution(void) {
    queue <int> q;
    for (int i = 1; i <= N; i++) {
        if (!indegree[i])
            q.push(i);
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        //출력 가능한 노드는 정답 벡터에 저장
        ans.push_back(now);
        for (int i = 0; i < node[now].size(); i++) {
            int next_node = node[now][i];
            indegree[next_node]--;
            if (!indegree[next_node])
                q.push(next_node);
        }
    }
    //정답 벡터에 모든 노드가 들어가 있어야 순서세우기가 가능한 경우
    if (ans.size() == N) {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << endl;
        }
    }
    else
        cout << 0;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Input();
    Solution();
    return 0;
}