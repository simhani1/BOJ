class Solution {
    final int INF = 123456789;
    int answer = INF;
    int[] dp;
    
    public int solution(int x, int y, int n) {
        dp = new int[y + 10];
        for(int i=1;i<=y;i++){
            dp[i] = INF;
        }
        dp[x] = 0;
        for(int i = x;i<=y;i++){
            if(i + n <= y)
                dp[i + n] = Math.min(dp[i+n], dp[i] + 1);
            if(i * 2 <= y)
                dp[i * 2] = Math.min(dp[i * 2], dp[i] + 1);
            if(i * 3 <= y)
                dp[i * 3] = Math.min(dp[i * 3], dp[i] + 1);
        }
        return answer = (dp[y] >= INF) ? -1 : dp[y];
    }
}