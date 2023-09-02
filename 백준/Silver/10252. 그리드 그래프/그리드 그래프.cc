#define _CRT_SECURE_NO_WARNINGS
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
using namespace std;
#define INF 2000000000
#define MOD 1000000
typedef long long ll;

int T, M,N;

void solve(void)
{
    vector<pair<int,int>> ans;
    // 높이 짝수
    if(M%2 == 0){
        for(int i=0;i<M;i++){
            if(i % 2 == 0){
                for(int j=0;j<N;j++){
                    ans.push_back({i,j});
                }
            }
            else{
                for(int j=N-1;j>=0;j--){
                    ans.push_back({i,j});
                }
            }
        }
    }
    // 높이 홀수
    else{
        for(int i=0;i<M;i++){
            ans.push_back({i,0});
        }
        for(int i=M-1;i>=0;i--){
            if(i % 2 == 0){
                for(int j=1;j<N;j++){
                    ans.push_back({i,j});
                }
            }
            else{
                for(int j=N-1;j>=1;j--){
                    ans.push_back({i,j});
                }
            }
        }
    }
    // print
    cout<<1<<"\n";
    for(auto i : ans){
        cout<<"("<<i.first<<","<<i.second<<")\n";
    }
}

void input(void)
{
    cin>>T;
    while(T--){
        cin>>M>>N;
        solve();
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
