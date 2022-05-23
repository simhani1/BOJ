#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <time.h>
#include <map>

using namespace std;

int N, A, B;
vector<int> tree[500001];
bool visited[500001];
int leaf = 0;
int cnt = 0;
int ans = 0;

//루트 노드로부터 모든 리프 노드까지의 거리를 모두 더한다.
void DFS(int start, int depth) {
    visited[start] = true;
    if (start != 1 && tree[start].size() == 1) {
        ans += depth;
    }
    for (int i = 0; i < tree[start].size(); i++) {
        int nextNode = tree[start][i];
        if (!visited[nextNode]) {
            cnt++;
            DFS(nextNode, depth + 1);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> A >> B;
        tree[B].push_back(A);
        tree[A].push_back(B);
    }
    DFS(1, 0);
    //홀수일 경우 승리
    if (ans % 2)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}