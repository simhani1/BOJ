#include <string>
#include <vector>

using namespace std;

int ans = 0;
bool visited[201];

void dfs(int n, int now, vector<vector<int>> v){
    for(int i=0;i<n;i++){
        if(!visited[i] && v[now][i]){
            visited[i]=true;
            dfs(n, i, v);
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i]=true;
            dfs(n,i,computers);
            ans++;
        }
    }    
    return ans;
}