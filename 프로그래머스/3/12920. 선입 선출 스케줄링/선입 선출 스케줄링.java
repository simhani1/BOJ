import java.util.*;

class Solution {
    
    int N, M, ans;
    int[] cores;
    
    public int solution(int n, int[] cores) {
        this.N = n; 
        this.M = cores.length;  // 코어의 수
        this.cores = cores;
        if (N <= M) {
            return N;
        }
        return solve();    
    }
    
    private int solve() {
        int time = 0, result = 0;
        int l = 1, r = 10000 * N;
        while(l <= r) {
            int mid = (l + r) / 2;
            int cnt = check(mid);
            if (cnt >= N) {
                r = mid - 1;
                time = mid;
                result = cnt;
            } else {
                l = mid + 1;
            }
        }
        result -= N;  // 목표 작업량 보다 초과한 작업
        for (int i = M - 1; i >= 0; i--) {
            if (time % cores[i] == 0) {
                if (result == 0) {
                    ans = i + 1;
                    break;
                }
                result--;
            }
        }
        return ans;
    }
    
    private int check(int target) {
        int cnt = M; // 제일 처음에 M개 처리
        for (int i = 0; i < M; i++) {
            cnt += (target / cores[i]);
        }
        return cnt;
    }
}