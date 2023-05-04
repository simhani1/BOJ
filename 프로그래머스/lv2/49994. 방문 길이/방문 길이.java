class Solution {
    public int solution(String dirs) {
        
        int cnt=0;
        String[] cmd = dirs.split("");
        boolean[][][] visited = new boolean[11][11][4];
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        int nowX = 5, nowY = 5;

        for (String i : cmd) {
            int d= 0;
            if (i.equals("U")) {
                d=0;
            } else if (i.equals("D")) {
                d=1;
            } else if (i.equals("R")) {
                d=2;
            } else if (i.equals("L")) {
                d=3;
            }
            int nextX = nowX + dx[d];
            int nextY = nowY + dy[d];
            if (0 <= nextX && nextX <= 10 && 0 <= nextY && nextY <= 10) {
                if (!visited[nextX][nextY][d]) {
                    visited[nextX][nextY][d] = true;
                    if (d % 2 == 0) {
                        d++;
                    } else {
                        d--;
                    }
                    visited[nowX][nowY][d] = true;
                    cnt++;
                }
                nowX = nextX;
                nowY = nextY;
            }
        }

        return cnt;
    }
}