import java.util.*;

class Solution {
    
    List<int[]> res = new ArrayList<>();
    public int[][] solution(int n) {
        
        dfs(n, 1, 2, 3);
        int[][] answer = new int[res.size()][2];
        for (int i = 0; i < res.size(); i++) {
            answer[i][0] = res.get(i)[0];
            answer[i][1] = res.get(i)[1];
        }
        return answer;
    }
    
    void dfs(int n, int from, int mid, int to) {
        if (n == 1) {
            res.add(new int[] {from, to});
            return;
        }
        dfs(n - 1, from, to, mid);
        res.add(new int[] {from, to});
        dfs(n - 1, mid, from, to);
    }
}