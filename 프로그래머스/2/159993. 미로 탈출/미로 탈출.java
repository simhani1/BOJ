import java.util.*;

class Pos {
    int x;
    int y;
    int cnt;
    
    public Pos(int x, int y, int cnt){
        this.x = x;
        this.y = y;
        this.cnt = cnt;
    }
}

class Solution {
    
    int N, M;
    int sX, sY, lX, lY, gX, gY;
    boolean flag = false;
    int[][] visited;
    int[] dx = {0,0,-1,1};
    int[] dy = {1,-1,0,0};
    
    public int solution(String[] maps) {
        N = maps.length;
        M = maps[0].length();
        int answer = 0;
        // 좌표 체크
        checkPos(maps);
        // s -> l bfs로 최단거리 계산
        answer += bfs(sX, sY, lX, lY, maps);
        // l -> g bfs로 최단거리 계산
        answer += bfs(lX, lY, gX, gY, maps);
        return (!flag) ? answer : -1;
    }
    
    private int bfs(int a, int b, int c, int d, String[] maps){
        visited = new int[N][M];
        Queue<Pos> q = new LinkedList<>();
        q.add(new Pos(a, b, 0));
        while(!q.isEmpty()){
            Pos pos = q.poll();
            int nowX = pos.x;
            int nowY = pos.y;
            int nowCnt = pos.cnt;
            if(visited[nowX][nowY] != 0)
                continue;
            visited[nowX][nowY] = nowCnt;
            if(nowX == c && nowY == d)
                break;
            for(int i=0;i<4;i++){
                int nextX = nowX + dx[i];
                int nextY = nowY + dy[i];
                if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
                    continue;
                // 벽이 아니라면 이동 가능
                if(maps[nextX].charAt(nextY) != 'X')
                    q.add(new Pos(nextX, nextY, nowCnt + 1));
            }
        }
        if(visited[c][d] == 0)
            flag = true;
        return visited[c][d];
    }
    
    private void checkPos(String[] maps){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(maps[i].charAt(j) == 'S'){
                    sX = i;
                    sY = j;
                }
                if(maps[i].charAt(j) == 'L'){
                    lX = i;
                    lY = j;
                }
                if(maps[i].charAt(j) == 'E'){
                    gX = i;
                    gY = j;
                }
            }
        }
    }
}