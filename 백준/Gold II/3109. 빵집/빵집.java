import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int R, C, ans = 0;
    private static char[][] arr = new char[10001][];
    private static boolean[][] visited = new boolean[10001][501];
    private static int[] dx = {-1, 0, 1};
    private static int[] dy = {1, 1, 1};


    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        for (int i = 0; i < R; i++) {
            String str = br.readLine();
            arr[i] = str.toCharArray();
        }
        for (int i = 0; i < R; i++) {
            dfs(i, 0);
        }
        System.out.println(ans);
    }

    private static boolean dfs(int nowX, int nowY) {
        /* 끝에 도달한 경우 */
        if (nowY == C - 1) {
            ans++;
            return true;
        }
        visited[nowX][nowY] = true;
        for (int i = 0; i < 3; i++) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C) {
                continue;
            }
            if (arr[nextX][nextY] == 'x') {
                continue;
            }
            if (visited[nextX][nextY]) {
                continue;
            }
            /* 끝에 도달했으면 더이상 탐색 금지 */
            if (dfs(nextX, nextY)) {
                return true;
            }
        }
        return false;
    }
}