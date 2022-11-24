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
#include <set>
using namespace std;
#define MAX 99999

string str;
int ans=MAX;

void solve(int l, int r, int cnt)
{
    if(cnt==4)
        return;
    if(l>r || l==r){
        ans=min(ans, cnt);
        return;
    }
    else{
        if(str[l]==str[r])
            solve(l+1, r-1, cnt);
        else{
            solve(l+1, r,cnt+1);
            solve(l,r-1,cnt+1);
        }
        
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> str;
    solve(0, str.length() - 1, 0);
    if(ans==MAX)
        cout<< -1<<endl;
    else
        cout<<ans<<endl;
    return 0;
}
