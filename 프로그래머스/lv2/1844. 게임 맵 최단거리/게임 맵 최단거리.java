import java.util.*;

class Solution {

    public int solution(int[][] maps) {
        boolean[][] visited = new boolean[101][101];
        int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
        int ans = 0;
        int goalX = maps.length - 1;
        int goalY = maps[0].length - 1;
        
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0, 0, 1});
        while (!q.isEmpty()) {
            int[] now = q.poll();
            int nowX = now[0], nowY = now[1], cnt = now[2];
            if (nowX == goalX && nowY == goalY) {
                ans = cnt;
                break;
            }
            for (int i = 0; i < 4; i++) {
                int nextX = nowX + dx[i];
                int nextY = nowY + dy[i];
                if (0 <= nextX && nextX < goalX + 1 && 0 <= nextY && nextY < goalY + 1) {
                    if (!visited[nextX][nextY] && maps[nextX][nextY] == 1) {
                        visited[nextX][nextY] = true;
                        q.add(new int[]{nextX, nextY, cnt + 1});
                    }
                }
            }
        }
        return (ans == 0) ? -1 : ans;
    }
    
}