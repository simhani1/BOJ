#include <string>
#include <vector>

using namespace std;

int ans = 0;

void dfs(vector<int> v, int target, int sum, int idx){
    if(idx == v.size()){
        if(sum == target)
            ans++;
        return;
    }
    dfs(v, target, sum + v[idx], idx + 1);
    dfs(v, target, sum - v[idx], idx + 1);
}


int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return ans;
}