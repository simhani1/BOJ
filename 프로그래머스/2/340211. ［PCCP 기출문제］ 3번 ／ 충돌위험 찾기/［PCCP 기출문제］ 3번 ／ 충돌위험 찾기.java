import java.util.*;

class Solution {
    
    int N, M, X;
    int[][] points, routes;
    Map<Point, Integer> map;
    
    class Point {
        int x, y, time;
        
        public Point(int x, int y, int time) {
            this.x = x; 
            this.y = y;
            this.time = time;
        }
        
        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj == null || getClass() != obj.getClass()) return false;
            Point point = (Point) obj;
            return x == point.x && y == point.y && time == point.time;
        }
        
        @Override
        public int hashCode() {
            return Objects.hash(x, y, time);
        }
    }
    
    public int solution(int[][] points, int[][] routes) {
        this.points = points;
        this.routes = routes;
        map = new HashMap<>();
        N = points.length;
        X = routes.length; 
        M = routes[0].length;
        
        solve();
        
        int ret = 0;
        for (int cnt : map.values()) {
            if (cnt > 1) ret++;
        }
        return ret;
    }
    
    public void solve() {
        for (int i = 0; i < X; i++) {
            int time = 0;
            int[] route = routes[i];
            update(points[route[0] - 1][0], points[route[0] - 1][1], time);
            for (int j = 1; j < M; j++) {
                int start = route[j - 1] - 1; 
                int end = route[j] - 1;
            
                int sx = points[start][0], sy = points[start][1];
                int gx = points[end][0], gy = points[end][1];
                
                int dx = sx <= gx ? 1 : -1;
                int dy = sy <= gy ? 1 : -1;

                while (sx != gx) {
                    sx += dx;
                    update(sx, sy, ++time);
                } 
                while (sy != gy) {
                    sy += dy; 
                    update(sx, sy, ++time);
                }
            }
        }
    }
    
    public void update(int x, int y, int time) {
        Point p = new Point(x, y, time);
        map.put(p, map.getOrDefault(p, 0) + 1);
    }
}

/*
포인트 순서대로 방문 
로봇 x대
다음 포인트로 최단 경로로 이동함. 좌우 > 상하
이동 중 2대 이상이 함께 존재하는 경우의 수 합하기
*/