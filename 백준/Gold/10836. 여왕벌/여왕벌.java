import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N, M, zeroCnt, oneCnt, twoCnt;
    private static int[] arr;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        arr = new int[2 * M - 1];
        Arrays.fill(arr, 1);
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int idx = 0;
            zeroCnt = Integer.parseInt(st.nextToken());
            oneCnt = Integer.parseInt(st.nextToken());
            twoCnt = Integer.parseInt(st.nextToken());
            while (zeroCnt-- > 0) {
                arr[idx++] += 0;
            }
            while (oneCnt-- > 0) {
                arr[idx++] += 1;
            }
            while (twoCnt-- > 0) {
                arr[idx++] += 2;
            }
        }
        for (int i = 1; i <= M; i++) {
            sb.append(arr[M - i]).append(" ");
            for (int j = M; j < 2 * M - 1; j++) {
                sb.append(arr[j]).append(" ");
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
}