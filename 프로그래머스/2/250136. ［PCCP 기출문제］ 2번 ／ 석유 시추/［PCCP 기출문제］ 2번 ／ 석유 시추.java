import java.util.*;

class Solution {
    int N, M, pk;
    int[][] land, arr;
    int[] dx = {0, 0, -1, 1}, dy = {-1, 1, 0, 0};
    Map<Integer, Integer> map;
    Set<Integer> visited;
    
    public int solution(int[][] land) {
        this.land = land; 
        N = land.length;
        M = land[0].length;
        pk = 1;
        map = new HashMap<>();
        visited = new HashSet<>();
        arr = new int[N][M];
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (land[i][j] == 1 && arr[i][j] == 0) {
                    bfs(i, j);
                }
            }
        }
        
        int ret = 0;
        for (int j = 0; j < M; j++) {
            visited.clear();
            int cnt = 0;
            for (int i = 0; i < N; i++) {
                if (arr[i][j] != 0 && !visited.contains(arr[i][j])) {
                    cnt += map.get(arr[i][j]);
                    visited.add(arr[i][j]);
                }
            }
            ret = Math.max(ret, cnt);
        }
        return ret;
    }
    
    public void bfs(int x, int y) {
        Queue<Node> q = new ArrayDeque<>();
        q.offer(new Node(x, y));
        arr[x][y] = pk;
        int cnt = 0;
        while (!q.isEmpty()) {
            Node node = q.poll();
            int nowX = node.x;
            int nowY = node.y; 
            cnt++;
            for (int i = 0; i < 4; i++) {
                int nextX = nowX + dx[i];
                int nextY = nowY + dy[i];
                if (!(0 <= nextX && nextX < N && 0 <= nextY && nextY < M)) 
                    continue;
                if (land[nextX][nextY] == 0) 
                    continue;
                if (arr[nextX][nextY] == 0) {
                    arr[nextX][nextY] = pk;
                    q.offer(new Node(nextX, nextY));   
                }
            }
        }
        map.put(pk++, cnt);  // 석유 크기 맵핑
    }
    
    class Node {
        int x, y;
        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}