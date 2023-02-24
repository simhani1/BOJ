#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int cnt = 0;
bool visited[20001];
int dist[20001];
vector<int> v[20001];


void bfs(int start){
    queue<int> q;
    q.push(start);
    dist[start]=0;
    while(!q.empty()){
        int now=q.front();
        visited[now]=true;
        q.pop();
        int next = v[now][0];
        for(int i=0;i<v[now].size();i++){
            int next = v[now][i];
            if(dist[next]==-1){
                q.push(next);
                dist[next]=dist[now]+1;
                cnt=max(cnt, dist[next]);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer=0;
    sort(edge.begin(), edge.end());
    for(int i=0;i<edge.size();i++){
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    fill(dist, dist+20001, -1);
    bfs(1);    
    for(int i=1;i<=n;i++){
        if(dist[i]==cnt)
            answer++;
    }
    return answer;
}