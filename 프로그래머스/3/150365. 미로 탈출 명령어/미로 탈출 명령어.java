import java.util.*;

class Solution {
    int N, M;
    int sx, sy, gx, gy, k;
    String ans;
    int[] dx = {1, 0, 0, -1}, dy = {0, -1, 1, 0};
    String[] dir = {"d", "l", "r", "u"};
    
    public String solution(int n, int m, int x, int y, int r, int c, int k) {
        N = n;
        M = m;
        sx = x;sy = y;gx = r;gy = c;
        this.k = k;
        ans = null;
        if (k < distFrom(sx, sy)) {
        }
        else if (distFrom(sx, sy) % 2 == 1 && k % 2 == 0) {
        }
        else if (distFrom(sx, sy) % 2 == 0 && k % 2 == 1) {
        }
        else {
            dfs(sx, sy, new StringBuilder());   
        }
        return ans == null ? "impossible" : ans;
    }
    
    public void dfs(int nowX, int nowY, StringBuilder sb) { 
        if (ans != null)
            return;
        if (k - sb.length() < distFrom(nowX, nowY))
            return;
        if (sb.length() == k) {
            if (nowX == gx && nowY == gy)
                ans = sb.toString();
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (!(1 <= nextX && nextX <= N && 1 <= nextY && nextY <= M))
                continue;
            dfs(nextX, nextY, sb.append(dir[i]));
            sb.deleteCharAt(sb.length() - 1);
        }
    }
    
    public int distFrom(int nowX, int nowY) {
        return Math.abs(nowX - gx) + Math.abs(nowY - gy);
    }
}