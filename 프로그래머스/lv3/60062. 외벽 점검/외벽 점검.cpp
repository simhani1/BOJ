#include <string>
#include <vector>
#include <algorithm>
#define INF 123456789
using namespace std;

int N, answer = INF;
vector<int> Weak, Dist;

void solve(int cnt, int nowIdx, int visited){
    if(cnt > Dist.size())
        return;
    for(int i=0;i<Weak.size();i++){
        int nextIdx = (nowIdx + i) % Weak.size();
        int diff = Weak[nextIdx] - Weak[nowIdx];  // 다음 취약점까지의 거리
        if(nextIdx < nowIdx)  // 원을 넘어가는 경우
            diff += N;
        // 방문 못하는 경우
        if(diff > Dist[Dist.size() - cnt])
            break;
        visited |= 1 << nextIdx;  // 다음 취약점을 방문처리
    }
    if(visited == ((1 << Weak.size()) - 1)){  // 모든 취약점을 방문했다면
        answer = min(answer, cnt);
        return;
    }
    for(int i=0;i<Weak.size();i++){
        if(visited & (1 << i))
            continue;
        solve(cnt+1, i, visited);
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    sort(dist.begin(), dist.end());
    N = n;
    Weak = weak;
    Dist = dist;
    for(int i=0;i<Weak.size();i++){
        solve(1, i, 0);
    }
    if(answer == INF)
        answer = -1;
    return answer;
}