import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N;
    private static char[][] arr;
    private static int[][] door;
    private static boolean[][][] visited;
    private static int[] dx = {1, 0, -1, 0};
    private static int[] dy = {0, -1, 0, 1};

    static class Node {
        int x;
        int y;
        int dir;
        int mirrorCnt;

        public Node(int x, int y, int dir, int mirrorCnt) {
            this.x = x;
            this.y = y;
            this.dir = dir;
            this.mirrorCnt = mirrorCnt;
        }

        @Override
        public String toString() {
            return "Node{" +
                    "x=" + x +
                    ", y=" + y +
                    ", dir=" + dir +
                    ", mirrorCnt=" + mirrorCnt +
                    '}';
        }
    }

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        arr = new char[N + 1][N + 1];
        door = new int[2][2];
        visited = new boolean[N + 1][N + 1][4];
        int idx = 0;
        for (int i = 0; i < N; i++) {
            arr[i] = br.readLine().toCharArray();
            for (int j = 0; j < N; j++) {
                if (arr[i][j] == '#') {
                    door[idx][0] = i;
                    door[idx][1] = j;
                    idx++;
                }
            }
        }
        System.out.println(bfs(door[0][0], door[0][1]));
    }

    private static int bfs(int x, int y) {
        int ans = 0;
        PriorityQueue<Node> pq = new PriorityQueue<>((o1, o2) -> Integer.compare(o1.mirrorCnt, o2.mirrorCnt));
        for (int i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if (0 <= nextX && nextX < N && 0 <= nextY && nextY < N && arr[nextX][nextY] != '*') {
                pq.offer(new Node(x, y, i, 0));
            }
        }
        while (!pq.isEmpty()) {
            Node node = pq.poll();
            int nowX = node.x;
            int nowY = node.y;
            int dir = node.dir;
            int mirrorCnt = node.mirrorCnt;
            if (visited[nowX][nowY][dir]) {
                continue;
            }
            visited[nowX][nowY][dir] = true;
            if (nowX == door[1][0] && nowY == door[1][1]) {
                ans = mirrorCnt;
                break;
            }
            int nextX = nowX + dx[dir];
            int nextY = nowY + dy[dir];
            if (0 <= nextX && nextX < N && 0 <= nextY && nextY < N && arr[nextX][nextY] != '*') {
                if (arr[nextX][nextY] == '!') {
                    if (dir == 0 || dir == 2) {
                        pq.offer(new Node(nextX, nextY, 1, mirrorCnt + 1));
                        pq.offer(new Node(nextX, nextY, 3, mirrorCnt + 1));
                    } else if (dir == 1 || dir == 3) {
                        pq.offer(new Node(nextX, nextY, 0, mirrorCnt + 1));
                        pq.offer(new Node(nextX, nextY, 2, mirrorCnt + 1));
                    }
                }
                pq.offer(new Node(nextX, nextY, dir, mirrorCnt));
            }
        }
        return ans;
    }
}