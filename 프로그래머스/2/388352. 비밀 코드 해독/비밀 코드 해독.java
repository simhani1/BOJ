import java.util.*;

class Solution {
    int N, answer;
    int[][] q;
    int[] ans;
    public int solution(int n, int[][] q, int[] ans) {
        this.N = n;
        this.q = q;
        this.ans = ans;
        this.answer = 0;
        
        dfs(0, 0, 0);
        
        return answer;
    }
    
    void dfs(int bit, int prev, int depth) {
        if (depth == 5) {
            if (check(bit)) {
                answer++;
            }
            return;
        }
        for (int i = prev + 1; i <= N; i++) {
            int tmp = 1 << i;
            bit |= tmp;
            dfs(bit, i, depth + 1);
            bit &= ~tmp;
        }
    }
    
    boolean check(int bit) {
        for (int i = 0; i < q.length; i++) {
            int cnt = 0;
            for (int num : q[i]) {
                if ((bit & 1 << num) != 0) {
                    cnt++;
                }
            }
            if (cnt != ans[i]) {
                return false;
            }
        }
        return true;
    }
}