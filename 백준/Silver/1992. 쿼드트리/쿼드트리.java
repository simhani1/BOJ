import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N;
    private static int[][] arr = new int[65][65];

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            for (int j = 0; j < N; j++) {
                arr[i][j] = line.charAt(j) - '0';
            }
        }
        solve(0, 0, N);
        System.out.println(sb.toString());
    }

    private static void solve(int x, int y, int size) {
        int target = arr[x][y];
        for (int i = x; i < x + size; i++) {
            for (int j = y; j < y + size; j++) {
                if (arr[i][j] != target) {
                    int nextSize = size / 2;
                    sb.append("(");
                    solve(x, y, nextSize);
                    solve(x, y + nextSize, nextSize);
                    solve(x + nextSize, y, nextSize);
                    solve(x + nextSize, y + nextSize, nextSize);
                    sb.append(")");
                    return;
                }
            }
        }
        sb.append(target == 0 ? 0 : 1);
    }
}