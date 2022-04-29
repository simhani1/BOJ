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

int N, workCnt, node;
int arr_time[10001], min_time[10001], indegree[10001];
vector <int> v[10001];
queue <int> q;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    //k == 현재 노드
    for (int i = 1; i <= N; i++) {
        cin >> arr_time[i];
        cin >> workCnt;
        //node == 현재 노드에 선행되는 노드들
        for (int j = 0; j < workCnt; j++) {
            cin >> node;
            v[node].push_back(i);
            indegree[i] += 1;
        }
    }
    //선행 간선이 없는 노드들을 큐에 저장
    for (int i = 1; i <= N; i++) {
        if (!indegree[i]) {
            q.push(i);
            min_time[i] = arr_time[i];
        }
    }
    //선행노드를 now, 선행노드에서 이어지는 다음 노드를 next_node
    for (int i = 1; i <= N; i++) {
        int now = q.front();
        q.pop();
        for (int j = 0; j < v[now].size(); j++) {
            int next_node = v[now][j];
            indegree[next_node] -= 1;
            //다음 작업을 수행하기 위한 최소 시간을 저장
            //현재 작업까지의 수행 시간 + 다음 작업까지의 수행시간 보다 현재 작업까지의 시간이 더 길다면 그것이 최소시간
            min_time[next_node] = max(min_time[next_node], min_time[now] + arr_time[next_node]);
            if (!indegree[next_node])
                q.push(next_node);
        }
    }
    //최소 작업 시간들 중, 모든 작업을 수행할 수 있는 최대 시간이 정답
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, min_time[i]);
    }
    cout << ans;
    return 0;
}