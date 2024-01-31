import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * @author
 * 심종한
 * @date
 * 2024-01-31
 * @link
 * https://www.acmicpc.net/problem/11660
 * @keyword_solution
 * pSum[i][j] = (0,0) ~ (i,j)까지의 총합
 * pSum[x2][y2] - pSum[x1 - 1][y2] - pSum[x2][y1 - 1] + pSum[x1 - 1][y1 - 1]
 * @input
 * @output
 * @time_complex
 * O(M)
 * @perf
 * 메모리: 121,928kb 시간: 852ms
 */
public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, M;
    private static int[][] pSum = new int[1025][1025];
    private static int[][] arr = new int[1025][1025];

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        calcSum();
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());
            sb.append(solve(x1, y1, x2, y2))
                    .append("\n");
        }
        System.out.println(sb.toString());
    }

    private static int solve(int x1, int y1, int x2, int y2) {
        return pSum[x2][y2] - pSum[x1 - 1][y2] - pSum[x2][y1 - 1] + pSum[x1 - 1][y1 - 1];
    }

    private static void calcSum() {
        // 가로
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                pSum[i][j] = pSum[i][j - 1] + arr[i][j];
            }
        }
        // 세로
        for (int j = 1; j <= N; j++) {
            for (int i = 1; i <= N; i++) {
                pSum[i][j] += pSum[i - 1][j];
            }
        }
    }
}