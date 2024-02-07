import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N,M, R, num;
    private static int[][] arr = new int[310][310];
    private static int[][] ans = new int[310][310];
    private static int[][] idxArr = new int[310][310];
    private static HashMap<Integer, Pair> map;
    private static int[] dx = {0, 1, 0, -1};
    private static int[] dy = {-1, 0, 1, 0};

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= M; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for (int k = 1; k <= Math.min(N, M) / 2; k++) {
            num = 1;
            map = new HashMap<>();
            int goal = (N - 1 - ((k - 1) * 2) + M - ((k - 1) * 2) - 1) * 2;
            dfs(k, k, goal, 0);
            num--;
            for (Integer start : map.keySet()) {
                int end = (start + R) % num == 0 ? num : (start + R) % num;
                Pair from = map.get(start);
                Pair to = map.get(end);
                ans[to.x][to.y] = arr[from.x][from.y];
            }
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                sb.append(ans[i][j])
                        .append(" ");
            }
            sb.append("\n");
        }
        System.out.println(sb.toString());
    }

    private static void dfs(int nowX, int nowY, int goal, int dir) {
        if (num == goal + 1) {
            return;
        }
        idxArr[nowX][nowY] = num;
        map.put(num, new Pair(nowX, nowY));
        num++;
        int nextX = nowX + dx[dir];
        int nextY = nowY + dy[dir];
        int nextDir = (dir + 1) % 4;
        if (idxArr[nextX][nextY] != 0) {
            dfs(nowX + dx[nextDir], nowY + dy[nextDir], goal, nextDir);
        } else if (1 <= nextX && nextX <= N && 1 <= nextY && nextY <= M) {
            dfs(nextX, nextY, goal, dir);
        } else {
            dfs(nowX + dx[nextDir], nowY + dy[nextDir], goal, nextDir);
        }
    }
}

class Pair {

    int x;
    int y;

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}