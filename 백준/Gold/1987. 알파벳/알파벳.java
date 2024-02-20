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
    private static int[][] visited = new int[21][21];

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        for (int i = 0; i < R; i++) {
            arr[i] = br.readLine().toCharArray();
        }
        dfs(0, 0, 1, 1 << arr[0][0] - 'A');
        System.out.println(ans);
    }

    private static void dfs(int nowX, int nowY, int cnt, int bit) {
        ans = Math.max(ans, cnt);
        visited[nowX][nowY] = bit;
        if (ans == 26) {
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C) {
                continue;
            }
            /* 현재 문자를 이미 탐색한 경우 */
            if ((bit & 1 << arr[nextX][nextY] - 'A') != 0) {
                continue;
            }
            /* 현재까지 방문했던 상태가 동일한 경우 */
            if ((bit | 1 << arr[nextX][nextY] - 'A') == visited[nextX][nextY]) {
                continue;
            }
            dfs(nextX, nextY, cnt + 1, bit | 1 << arr[nextX][nextY] - 'A');
        }
    }
}