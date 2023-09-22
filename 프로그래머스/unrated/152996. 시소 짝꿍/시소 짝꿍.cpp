#include <string>
#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

ll cnt[1001];

ll solution(vector<int> weights) {
    ll ans = 0;
    
    for(int i=0;i<weights.size();i++){
        cnt[weights[i]]++;
    }
    
    for(int i=0;i<weights.size();i++){
        ll now = weights[i];

        // 2 : 3
        if(now % 2 == 0){
            ll target = (now / 2) * 3;
            if(target <= 1000)
                ans += cnt[target];
        }
        // 3 : 4
        if(now % 3 == 0){
            ll target = (now / 3) * 4;
            if(target <= 1000)
                ans += cnt[target];
        }
        // 1 : 2
        ll target = now * 2;
        if(target <= 1000)
            ans += cnt[target];
    }
    for(int i=100; i<=1000;i++){
        if(cnt[i] >= 2){
            ans += (ll) ((cnt[i] * (cnt[i] - 1)) / 2);
        }
    }
    return ans;
}