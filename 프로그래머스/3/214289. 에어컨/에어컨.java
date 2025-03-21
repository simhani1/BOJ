import java.util.*;

/*
t1 ~ t2 사이의 온도를 유지해야 함
희망온도를 설정한다. 실내온도와 희망온도가 다르면, 1분 뒤 희망온도를 향해 +-1 
희망온도에 도달하면 더이상 온도 변화는 없다.
희망온도와 실내온도가 다르면 -> 매분 a 전력 소모, 같다면 b 전력 소모
승객이 탑승중일 때, 에어컨 소비전력을 최소화한다.
*/

class Solution {
    int N;
    int[][] dp;
    int INF = 987654321;
    
    public int solution(int temperature, int t1, int t2, int a, int b, int[] onboard) {
        // 0 ~ 50으로 조정
        temperature += 10;
        t1 += 10;
        t2 += 10;
        
        // 초기화
        N = onboard.length;
        dp = new int[N][51];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= 50; j++) {
                dp[i][j] = INF; 
            }
        }
        dp[0][temperature] = 0;
        
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j <= 50; j++) {
                if (onboard[i] == 1 && (j < t1 || j > t2)) {
                    continue;
                }
                
                // 에어컨을 켰을 때
                if (j >= 1) {
                    dp[i+ 1][j - 1] = Math.min(dp[i + 1][j - 1], dp[i][j] + a);
                }
                if (j < 50) {
                    dp[i + 1][j + 1] = Math.min(dp[i + 1][j + 1], dp[i][j] + a);
                }
                dp[i + 1][j] = Math.min(dp[i + 1][j], dp[i][j] + b);
                
                // 에어컨을 껐을 때
                if (j == temperature) {
                    dp[i + 1][j] = Math.min(dp[i + 1][j], dp[i][j]);
                } 
                if (j < temperature && j < 50) {
                    dp[i + 1][j + 1] = Math.min(dp[i + 1][j + 1], dp[i][j]);
                }
                if (j > temperature && j > 0) {
                    dp[i + 1][j - 1] = Math.min(dp[i + 1][j - 1], dp[i][j]);
                }
            }
        }
        int ans = INF;
        for (int i = 0; i <= 50; i++) {
            if (onboard[N - 1] == 1 && (i < t1 || i > t2)) {
                continue;
            }
            ans = Math.min(ans, dp[N - 1][i]);
        }
        return ans;
    }
}