import java.util.*;

class Solution {
    int[][] dist;
    final int INF = 123456789;
    public int solution(int n, int s, int a, int b, int[][] fares) {
        dist = new int[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            Arrays.fill(dist[i], INF);
            dist[i][i] = 0;
        }
        
        for (int i = 0; i < fares.length; i++) {
            int x = fares[i][0];
            int y = fares[i][1];
            int z = fares[i][2];
            dist[x][y] = dist[y][x] = z;
        }
        
        for (int k = 1; k <= n; k++) { 
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (i == k || k == j || i == j) {
                        continue;
                    }
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        int answer = INF;
        for (int k = 1; k <= n; k++) {
            int cost = dist[s][k] + dist[k][a] + dist[k][b];
            answer = Math.min(answer, cost);
        }
        return answer;
    }
}