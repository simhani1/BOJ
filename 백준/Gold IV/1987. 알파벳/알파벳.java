import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int R, C, ans;
    private static char[][] arr = new char[21][];
    private static int[] dx = {0, 0, -1, 1};
    private static int[] dy = {1, -1, 0, 0};
    private static boolean[] visited = new boolean[27];

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        for (int i = 0; i < R; i++) {
            arr[i] = br.readLine().toCharArray();
        }
        dfs(0, 0, 1);
        System.out.println(ans);
    }

    private static void dfs(int nowX, int nowY, int cnt) {
        visited[arr[nowX][nowY] - 'A'] = true;
        ans = Math.max(ans, cnt);
        for (int i = 0; i < 4; i++) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C) {
                continue;
            }
            if (visited[arr[nextX][nextY] - 'A']) {
                continue;
            }
            dfs(nextX, nextY, cnt + 1);
        }
        visited[arr[nowX][nowY] - 'A'] = false;
    }
}