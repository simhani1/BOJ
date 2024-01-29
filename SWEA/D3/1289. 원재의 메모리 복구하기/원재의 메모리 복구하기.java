import javax.xml.stream.events.StartDocument;
import java.awt.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * @author 심종한
 * @date 2024-01-29
 * @link https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV19AcoKI9sCFAZN
 * @keyword_solution
 * @input
 * 2
 * 0011
 * 100
 * @output
 * #1 1
 * #2 2
 * @time_complex
 * @perf
 */
public class Solution {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static int T, N;
    private static int[] arrTarget;
    private static int[] arrOrigin;


    public static void main(String[] args) throws Exception {
         br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(st.nextToken());
        for (int t = 1; t <= T; t++) {
            st = new StringTokenizer(br.readLine());
            String target = st.nextToken();
            // 배열로 변환
            N = target.length();
            arrTarget = new int[N];
            arrOrigin = new int[N];
            for (int i = 0; i < N; i++) {
                arrTarget[i] = target.charAt(i) - '0';
            }
            // solve
            sb.append("#")
                    .append(t)
                    .append(" ")
                    .append(solve())
                    .append("\n");
        }
        System.out.println(sb.toString());
    }

    private static int solve() {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (arrTarget[i] == arrOrigin[i]) {
                continue;
            }
            changeBit(arrTarget[i], i);
            cnt++;
        }
        return cnt;
    }

    private static void changeBit(int num, int startIdx) {
        for (int i = startIdx; i < N; i++) {
            arrOrigin[i] = num;
        }
    }
}