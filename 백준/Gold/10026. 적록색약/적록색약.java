import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N;
    private static char[][] arr;
    private static boolean[][] visited;
    private static int[] dx = {0, 0, -1, 1};
    private static int[] dy = {1, -1, 0, 0};

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());
        arr = new char[N + 1][];
        visited = new boolean[N + 1][N + 1];
        for (int i = 0; i < N; i++) {
            arr[i] = br.readLine().toCharArray();
        }
        int cntA = 0, cntB = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    dfs(i, j);
                    cntA++;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] == 'R') {
                    arr[i][j] = 'G';
                }
                visited[i][j] = false;
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    dfs(i, j);
                    cntB++;
                }
            }
        }
        System.out.println(sb.append(cntA)
                .append(" ")
                .append(cntB)
                .toString());
    }

    private static void dfs(int nowX, int nowY) {
        visited[nowX][nowY] = true;
        for (int i = 0; i < 4; i++) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N) {
                continue;
            }
            if (arr[nextX][nextY] != arr[nowX][nowY]) {
                continue;
            }
            if (visited[nextX][nextY]) {
                continue;
            }
            dfs(nextX, nextY);
        }
    }
}