import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, cntA = 0, cntB = 0, cntC = 0;
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
        System.out.println(sb.append(cntA)
                .append("\n")
                .append(cntB)
                .append("\n")
                .append(cntC)
                .toString());
    }

    private static void solve(int x, int y, int size) {
        int target = arr[x][y];
        for (int i = x; i < x + size; i++) {
            for (int j = y; j < y + size; j++) {
                if (arr[i][j] != target) {
                    int nextSize = size / 3;
                    solve(x, y, nextSize);
                    solve(x, y + nextSize, nextSize);
                    solve(x, y + 2 * nextSize, nextSize);

                    solve(x + nextSize, y, nextSize);
                    solve(x + nextSize, y + nextSize, nextSize);
                    solve(x + nextSize, y + 2 * nextSize, nextSize);

                    solve(x + 2 * nextSize, y, nextSize);
                    solve(x + 2 * nextSize, y + nextSize, nextSize);
                    solve(x + 2 * nextSize, y + 2 * nextSize, nextSize);
                    return;
                }
            }
        }
        if (target == -1) {
            cntA++;
        } else if (target == 0) {
            cntB++;
        } else {
            cntC++;
        }
    }
}