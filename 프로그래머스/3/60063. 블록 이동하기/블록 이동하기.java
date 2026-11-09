import java.util.*;

class Robot {
    int[] pos;
    int cost;
    public Robot(int[] pos, int cost) {
        this.pos = pos;
        this.cost = cost;
    }
}

class Solution {
    
    int N;
    int[][] board;
    boolean[][][][] visited;
    
    public int solution(int[][] board) {
        this.N = board.length;    
        this.board = board;
        this.visited = new boolean[N + 1][N + 1][N + 1][N + 1];
        int[] dx = {0, 0, -1, 1};
        int[] dy = {-1, 1, 0, 0};
        
        Queue<Robot> q = new ArrayDeque<>(); 
        q.offer(new Robot(new int[]{0, 0, 0, 1}, 0));
        visited[0][0][0][1] = true;
        
        int ret = Integer.MAX_VALUE;
        while (!q.isEmpty()) {
            Robot r = q.poll();
            int[] nowPos = r.pos;
            int nowCost = r.cost;
            
            if (goal(nowPos)) return nowCost;
            
            int x1 = nowPos[0], y1 = nowPos[1];
            int x2 = nowPos[2], y2 = nowPos[3];
            
            // 1. 이동 
            for (int i = 0; i < 4; i++) {
                int nx1 = x1 + dx[i], ny1 = y1 + dy[i];
                int nx2 = x2 + dx[i], ny2 = y2 + dy[i];
                
                if (!(canMove(nx1, ny1) && canMove(nx2, ny2))) continue;
                
                add(q, new int[]{nx1, ny1, nx2, ny2}, nowCost + 1);
            }            
            
            // 가로 -> 세로 or 세로 -> 가로
            if (x1 == x2) {
                for (int d = -1; d <= 1; d += 2) {
                    if (!(canMove(x1 + d, y1) && canMove(x2 + d, y2))) continue;
                    // 왼쪽 축
                    add(q, new int[]{x1, y1, x1 + d, y1}, nowCost + 1);
                    // 오른쪽 축
                    add(q, new int[]{x2 + d, y2, x2, y2}, nowCost + 1);
                }
            } else {
                for (int d = -1; d <= 1; d += 2) {
                    if (!(canMove(x1, y1 + d) && canMove(x2, y2 + d))) continue;
                    // 위쪽 축
                    add(q, new int[]{x1, y1, x1, y1 + d}, nowCost + 1);
                    // 아래쪽 축
                    add(q, new int[]{x2, y2 + d, x2, y2}, nowCost + 1);                    
                }
            }
        }
        return ret;
    }    
    
    void add(Queue<Robot> q, int[] pos, int cost) {
        int x1 = pos[0], y1 = pos[1];
        int x2 = pos[2], y2 = pos[3];
        
        if (x1 > x2 || (x1 == x2 && y1 > y2)) {
            int tmpX = x1;
            x1 = x2;
            x2 = tmpX;
            
            int tmpY = y1;
            y1 = y2; 
            y2 = tmpY;
        }
        
        if (visited[x1][y1][x2][y2]) return;
        
        visited[x1][y1][x2][y2] = true;
        q.offer(new Robot(
                    new int[]{x1, y1, x2, y2},
                    cost
        ));
    }
    
    boolean canMove(int x, int y) {
        return 
            0 <= x && x < N &&
            0 <= y && y < N &&
            board[x][y] == 0;
    }
    
    boolean goal(int[] pos) {
        return
            (pos[0] == N - 1 && pos[1] == N - 1) ||
            (pos[2] == N - 1 && pos[3] == N - 1);
    }
}