#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <cmath>
using namespace std;
#define INF 123456789
#define MAX 1000001
#define MOD 987654321
typedef long long ll;

int T, N, ans;
int sX, sY, eX, eY;
vector<pair<int,int>> v;
bool visited[15];

int calc(int a, int b, int c, int d){
    return abs(a - c) + abs(b - d);
}

void dfs(int idx, int pSum, int cnt){
    if(cnt == N){
        ans = min(ans, pSum + calc(v[idx].first, v[idx].second, v[N+1].first, v[N+1].second));
        return;
    }
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(i, pSum + calc(v[idx].first, v[idx].second, v[i].first, v[i].second), cnt + 1);
            visited[i] = false;
        }
    }
}

void solve(void)
{
    cin>>T;
    for(int t=1;t<=T;t++){
        // init
        ans = INF;
        v.clear();
        fill(visited, visited + 15, false);
        //input
        cin>>N;
        cin>>sX>>sY>>eX>>eY;
        v.push_back({sX, sY});
        for(int i=0, A,B;i<N;i++){
            cin>>A>>B;
            v.push_back({A,B});
        }
        v.push_back({eX, eY});
        // solve
        dfs(0, 0, 0);
        cout << "#" << t << " " << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
