import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, M;
    private static int[][] arr;
    private static boolean[][] visited;
    private static int[] dx = {0, -1, 0, 1};
    private static int[] dy = {-1, 0, 1, 0};

    public static void main(String[] args) throws Exception {
        /* input */
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new int[M][N];
        visited = new boolean[M][N];
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        /* solve */
        int maxArea = 0;
        int cnt = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    maxArea = Math.max(maxArea, dfs(i, j));
                    cnt++;
                }
            }
        }
        /* 벽 하나 제거 & 가장 큰 방의 넓이 */
        int removedMaxArea = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < 4; k++) {
                    init();
                    if ((arr[i][j] & (1 << k)) == (1 << k)) {
                        arr[i][j] &= ~(1 << k);
                        removedMaxArea = Math.max(removedMaxArea, dfs(i, j));
                        arr[i][j] |= (1 << k);
                    }
                }
            }
        }
        System.out.println(sb.append(cnt)
            .append("\n")
            .append(maxArea)
            .append("\n")
            .append(removedMaxArea));
    }

    private static void init() {
        for (int i = 0; i < M; i++) {
            Arrays.fill(visited[i], false);
        }
    }

    private static int dfs(int nowX, int nowY) {
        int sum = 1;
        visited[nowX][nowY] = true;
        for (int k = 0; k < 4; k++) {
            if ((arr[nowX][nowY] & (1 << k)) != 0) {
                continue;
            }
            int nextX = nowX + dx[k];
            int nextY = nowY + dy[k];
            if (isValid(nextX, nextY)) {
                sum += dfs(nextX, nextY);
            }
        }
        return sum;
    }

    private static boolean isValid(int x, int y) {
        return 0 <= x && x < M && 0 <= y && y < N && !visited[x][y];
    }
}