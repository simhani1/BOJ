import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, blueCnt = 0, whiteCnt = 0;
    private static int[][] arr;

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());
        arr = new int[N + 1][N + 1];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        solve(0, 0, N);
        System.out.println(sb.append(whiteCnt)
                .append("\n")
                .append(blueCnt)
                .toString());
    }

    private static void solve(int x, int y, int size) {
        int target = arr[x][y];
        for (int i = x; i < x + size; i++) {
            for (int j = y; j < y + size; j++) {
                if (arr[i][j] != target) {
                    solve(x, y, size / 2);
                    solve(x, y + (size / 2), size / 2);
                    solve(x + (size / 2), y, size / 2);
                    solve(x + (size / 2), y + (size / 2), size / 2);
                    return;
                }
            }
        }
        if (target == 1) {
            blueCnt++;
        } else {
            whiteCnt++;
        }
    }
}