import java.util.*;

class Solution {
    
    private int[][][] dp = new int[41][121][121];
    private final int INF = 123456789;
    
    public int solution(int[][] info, int n, int m) {
        /* input */
        int answer = INF;
        int len = info.length;
        for (int i = 0; i <= len; i++) {
            for (int j = 0; j <= 120; j++) {
                for (int k = 0; k <= 120; k++) {
                    dp[i][j][k] = INF;
                }
            }
        }
        /* solve */
        dp[0][0][0] = 0;
        for (int i = 0; i < len; i++) {
            for (int a = 0; a < n; a++) {
                for (int b = 0; b < m; b++) {
                    if (dp[i][a][b] == INF) {
                        continue;
                    }
                    int nextA = a + info[i][0];
                    if (nextA < n) {
                        dp[i + 1][nextA][b] = Math.min(dp[i + 1][nextA][b], dp[i][a][b] + info[i][0]);
                    }
                    int nextB = b + info[i][1];
                    if (nextB < m) {
                        dp[i + 1][a][nextB] = Math.min(dp[i + 1][a][nextB], dp[i][a][b]);
                    }
                }
            }
        }
        /* answer */
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < m; b++) {
                // System.out.println("dp[len]" + "[" +  a + "][" + b + "] = " + dp[len][a][b]);
                answer = Math.min(answer, dp[len][a][b]);
            }
        }
        return answer == INF ? -1 : answer;
    }
}