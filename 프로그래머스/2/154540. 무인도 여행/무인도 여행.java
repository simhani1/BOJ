import java.util.*;

class Pos {
    int x;
    int y;
    
    Pos(int x, int y){
        this.x = x;
        this.y = y;
    }
}

class Solution {
    int N, M;
    int[] dx = {0,0,-1,1};
    int[] dy = {1,-1,0,0};
    boolean[][] visited;
    List<Integer> tmp = new ArrayList<>();
    
    public int[] solution(String[] maps) {
        N = maps.length;
        M = maps[0].length();
        visited = new boolean[N][M];
        for(int i=0;i<maps.length;i++){
            for(int j=0;j<maps[i].length();j++){
                if(maps[i].charAt(j) != 'X' && !visited[i][j])
                    tmp.add(dfs(i, j, maps[i].charAt(j) - '0', maps));
            }
        }
        if(tmp.isEmpty())
            tmp.add(-1);
        Collections.sort(tmp);
        int[] answer = new int[tmp.size()];
        return tmp.stream().mapToInt(Integer::intValue).toArray();
    }
    
    private int dfs(int nowX, int nowY, int sum, String[] maps){
        visited[nowX][nowY] = true;
        for(int i=0;i<4;i++){
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
                continue;
            if(maps[nextX].charAt(nextY) != 'X' && !visited[nextX][nextY])
                sum = dfs(nextX, nextY, sum + maps[nextX].charAt(nextY) - '0', maps);
        }
        return sum;
    }
}