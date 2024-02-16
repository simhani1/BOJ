import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, M, D;
    private static int[][] arr;
    private static int[][] archer = new int[3][2];
    private static int[] dx = {0, -1, 0};
    private static int[] dy = {-1, 0, 1};

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());
        arr = new int[N + 2][M + 1];
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= M; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        /* N+1행에 궁수 배치 */
        int ans = 0;
        for (int i = 1; i <= M - 2; i++) {
            for (int j = i + 1; j <= M - 1; j++) {
                for (int k = j + 1; k <= M; k++) {
                    archer[0][0] = N + 1;
                    archer[0][1] = i;
                    archer[1][0] = N + 1;
                    archer[1][1] = j;
                    archer[2][0] = N + 1;
                    archer[2][1] = k;
                    int[][] tmp = copyArr();
                    ans = Math.max(ans, kill(tmp));
                }
            }
        }
        System.out.println(ans);
    }

    private static int[][] copyArr() {
        int[][] tmp = new int[arr.length][arr[0].length];
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[0].length; j++) {
                tmp[i][j] = arr[i][j];
            }
        }
        return tmp;
    }

    private static int kill(int[][] tmp) {
        int cnt = 0;
        for (int t = 0; t <= N; t++) {

            /* 공격 */
            List<Node> nodeList = new ArrayList<>();
            for (int i = 0; i < 3; i++) {
                Node node = bfs(archer[i][0] - 1, archer[i][1], tmp);
                if (node != null) {
                    nodeList.add(node);
                }
            }

            /* 죽이기 */
            for (Node node : nodeList) {
                int x = node.x;
                int y = node.y;
                if (tmp[x][y] == 1) {
                    tmp[x][y] = 0;
                    cnt++;
                }
            }

            /* 이동 */
            tmp = move(tmp);
        }
        return cnt;
    }

    private static Node bfs(int startX, int startY, int[][] tmp) {
        Queue<Node> q = new ArrayDeque<>();
        q.offer(new Node(startX, startY, 1));
        while (!q.isEmpty()) {
            Node node = q.poll();
            int nowX = node.x;
            int nowY = node.y;
            int dist = node.dist;
            if (dist > D) {
                continue;
            }
            if (tmp[nowX][nowY] == 1) {
                return node;
            }
            for (int i = 0; i < 3; i++) {
                int nextX = nowX + dx[i];
                int nextY = nowY + dy[i];
                int nextDist = dist + 1;
                if (nextX < 1 || nextX > N || nextY < 1 || nextY > M) {
                    continue;
                }
                q.offer(new Node(nextX, nextY, nextDist));
            }
        }
        return null;
    }

    private static int[][] move(int[][] tmp) {
        int[][] newArr = new int[N + 2][M + 1];
        for (int i = 1; i <= N + 1; i++) {
            newArr[i] = tmp[i - 1];
        }
        return newArr;
    }

    static class Node {
        int x;
        int y;
        int dist;

        public Node(int x, int y, int dist) {
            this.x = x;
            this.y = y;
            this.dist = dist;
        }
    }
}