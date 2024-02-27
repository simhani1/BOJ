import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author
 * 심종한
 * @date
 * 2024-02-27
 * @link
 * https://www.acmicpc.net/problem/1463
 * https://drive.google.com/file/d/1yDp2SgGChA7LypQ4iR9i5AtxEN0NxKdg/view?usp=sharing
 * @keyword_solution
 * 10 -> 5 -> 4 -> 2 -> 1  == 4번 연산
 * 10 -> 9 -> 3 -> 1  == 3번 연산
 * 어떤 연산을 먼저 하는 것이 최적의 방법인지 판단할 수 없음
 * dp[i]: N을 i로 만들기 위한 최소 연산 횟수
 * @input
 * N <= 10^6
 * @output
 * @time_complex
 * O(N)
 * @perf
 * 메모리: 15,876kb, 시간: 116ms
 */
public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N;
    private static int[] dp;
    private static final int INF = 123456789;

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());
        /* i를 만드는데 필요한 최소 연산 횟수 */
        dp = new int[N + 1];
        Arrays.fill(dp, INF);
        dp[N] = 0;
        for (int i = N; i >= 1; i--) {
            if (i % 3 == 0) {
                dp[i / 3] = Math.min(dp[i / 3], dp[i] + 1);
            }
            if (i % 2 == 0) {
                dp[i / 2] = Math.min(dp[i / 2], dp[i] + 1);
            }
            dp[i - 1] = Math.min(dp[i - 1], dp[i] + 1);
        }
        System.out.println(dp[1]);
    }
}