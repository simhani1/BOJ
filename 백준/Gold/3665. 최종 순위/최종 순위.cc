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

int T, N, M;
int A, B;
vector<int> teamRank;
vector<int> indegree;
vector<int> ans;
int node[501][501];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> N;
        // resize: 용량을 미리 확보하고, 아직 값이 저장 안된 부분을 매개변수 값으로 초기화
        //따라서 마지막에 벡터들을 모두 clear함수로 정리를 해야 문제가 발생하지 않는다
        teamRank.resize(N + 1, 0);
        indegree.resize(N + 1, 0);
        memset(node, 0, sizeof(node));
        for (int i = 1; i <= N; i++)
        {
            int t;
            cin >> t;
            teamRank[t] = i; //각 팀의 등수를 저장
        }
        for (int i = 1; i <= N; i++)
        {
            for (int j = i + 1; j <= N; j++)
            {
                //현재 팀보다 다음 팀의 등수가 낮을 경우
                if (teamRank[i] < teamRank[j])
                {
                    node[i][j] = 1;
                    indegree[j]++;
                }
                //현재 팀보다 다음 팀의 등수가 높을 경우
                else
                {
                    node[j][i] = 1;
                    indegree[i]++;
                }
            }
        }
        cin >> M;
        for (int i = 0; i < M; i++)
        {
            cin >> A >> B;
            // B의 등수가 더 낮을 경우
            if (teamRank[A] < teamRank[B])
            {
                node[A][B] = 0;
                node[B][A] = 1;
                indegree[A]++;
                indegree[B]--;
            }
            // A의 등수가 더 낮을 경우
            else
            {
                node[A][B] = 1;
                node[B][A] = 0;
                indegree[A]--;
                indegree[B]++;
            }
        }
        //위상 정렬
        queue<int> q;
        for (int i = 1; i <= N; i++)
        {
            if (!indegree[i])
                q.push(i);
        }
        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            ans.push_back(now);
            for (int i = 1; i <= N; i++)
            {
                //현재 팀보다 등수가 높은 팀이 존재할 경우
                if (node[now][i])
                {
                    indegree[i]--;
                    if (!indegree[i])
                        q.push(i);
                }
            }
        }
        if (ans.size() == N)
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << " ";
            }
        }
        else
            cout << "IMPOSSIBLE";
        cout << endl;
        teamRank.clear();
        indegree.clear();
        ans.clear();
    }
    return 0;
}