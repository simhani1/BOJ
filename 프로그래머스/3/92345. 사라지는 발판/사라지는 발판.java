import java.util.*;

class Solution {
    
    final int INF = Integer.MAX_VALUE;
    int N, M;
    int[][] board;
    int[] dx = {0, 0, -1, 1}, dy = {-1, 1, 0, 0};
    
    static class Result {
        boolean win;
        int cnt; 
        
        public Result(boolean win, int cnt) {
            this.win = win;
            this.cnt = cnt;
        }
    }
    
    public int solution(int[][] board, int[] aloc, int[] bloc) {
        this.board = board;
        N = board.length;
        M = board[0].length;
        Result result = dfs(aloc[0], aloc[1], bloc[0], bloc[1]);
        return result.cnt;
    }
    
    public Result dfs(int x1, int y1, int x2, int y2) {
        if (isFinished(x1, y1)) 
            return new Result(false, 0); 
        boolean canWin = false;
        int maxCnt = -INF;
        int minCnt = INF;
        int nowX = x1;
        int nowY = y1;
        board[nowX][nowY] = 0;
        for (int i = 0; i < 4; i++) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (!inRange(nextX, nextY) || board[nextX][nextY] == 0)
                continue;
            Result result = dfs(x2, y2, nextX, nextY);
            if (result.win) {
                maxCnt = Math.max(maxCnt, result.cnt);
            } else {
                canWin = true;
                minCnt = Math.min(minCnt, result.cnt);
            }    
        }
        board[nowX][nowY] = 1;
        return new Result(canWin, (canWin ? minCnt : maxCnt) + 1);
    }
    
    public boolean isFinished(int nowX, int nowY) {
        if (board[nowX][nowY] == 0)
            return true;
        for (int i = 0; i < 4; i++) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (inRange(nextX, nextY) && board[nextX][nextY] == 1)
                return false;
        }
        return true;
    }
    
    public boolean inRange(int x, int y) {
        return 0 <= x && x < N && 0 <= y && y < M;
    }
}