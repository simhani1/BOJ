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
#define MOD 1000000
typedef long long ll;

int T, N;
vector<int> v;

void solve(void)
{
    int ans = 0;
    sort(v.begin(), v.end());
    for(int i=0;i<=N-3;i++){
        ans = max(ans, abs(v[i] - v[i+2]));
    }
    cout<<ans<<"\n";
}

void init(void){
    v.clear();
}

void input(void)
{
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=0,X;i<N;i++){
            cin>>X;
            v.push_back(X);
        }
        solve();
        init();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    return 0;
}
