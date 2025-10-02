class Solution {
    int N;
    int[] dp;
    int MOD = 10007;
    public int solution(int n, int[] tops) {
        N = n * 2 + 1;
        dp = new int[N];
        dp[0] = 1;
        dp[1] = tops[0] == 1 ? 3 : 2;
        for (int i = 2; i < N; i++) {
            if (i % 2 == 1 && tops[i / 2] == 1) {
                dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % MOD;
            } else {
                dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
            }
        }
        return dp[N - 1];
    }
}