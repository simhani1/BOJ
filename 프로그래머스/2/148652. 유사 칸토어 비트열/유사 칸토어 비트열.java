class Solution {
    int N;
    long L, R;
    public int solution(int n, long l, long r) {
        this.N = n;
        this.L = l;
        this.R = r;
        
        long len = 1;
        for (int i = 0; i < N; i++) {
            len *= 5;
        }
        
        return dfs(N, 1, len);
    }
    
    int dfs(int depth, long start, long end) { 
        if (end < L || R < start) {
            return 0;
        }
        
        if (depth == 0) {
            return 1;
        }
        
        long size = (end - start + 1) / 5; 
        int cnt = 0; 
        for (int i = 0; i < 5; i++) {
            if (i == 2) continue;
            long nextStart = start + size * i;
            long nextEnd = nextStart + size - 1;
            cnt += dfs(depth - 1, nextStart, nextEnd);
        }
        return cnt;
    }
}