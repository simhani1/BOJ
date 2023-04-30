import java.util.*;

class Pos {
    int x;
    int y;
    int level;
    
    public Pos(int x, int y, int level) {
        this.x = x;
        this.y = y;
        this.level = level;
    }
}

class Solution {
    
    char arr[][];
    boolean visited[][];
    int dx[] = {0,0,-1,1};
    int dy[] = {1,-1,0,0};
    int row;
    int col;
    
    
    public Pos getNextPos(int cmd, Pos pos) {
        int x = pos.x, y = pos.y, level = pos.level;
        int mX = dx[cmd], mY = dy[cmd];
        while (0 <= x + mX && x + mX < row && 0 <= y + mY && y + mY < col && arr[x + mX][y + mY] != 'D') {
            x += mX;
            y += mY;
        }
        return new Pos(x, y, level + 1);
    }
    
    public int bfs(Pos start, Pos goal) {
        Queue<Pos> q = new LinkedList<>();
        q.add(start);
        while (!q.isEmpty()) {
            Pos nowPos = q.poll();
            int nowX = nowPos.x;
            int nowY = nowPos.y;
            int nowLevel = nowPos.level;
            if (nowX == goal.x && nowY == goal.y) {
                return nowLevel;
            }
            for (int i = 0; i < 4; i++) {
                Pos nextPos = getNextPos(i, nowPos);
                if (!visited[nextPos.x][nextPos.y]) {
                    visited[nextPos.x][nextPos.y] = true;
                    q.add(nextPos);
                }
            }
        }
        return -1;
    }
    
    public int solution(String[] board) {
        int answer = 0;
        row = board.length;
        col = board[0].length();

        arr = new char[row][col];
        visited = new boolean[row][col];

        Pos start = null;
        Pos goal = null;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                arr[i][j] = board[i].charAt(j);
                if (arr[i][j] == 'R') {
                    start = new Pos(i, j, 0);
                } else if (arr[i][j] == 'G') {
                    goal = new Pos(i, j, 0);
                }
            }
        }

        answer = bfs(start, goal);
        return answer;
    }
}