import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, D, K, C;
    private static int[] arr;
    private static int[] foodCnt;
    private static int totalCnt = 1, ans = 0;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        arr = new int[2 * N + 1];
        foodCnt = new int[3001];
        for (int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
            arr[i + N] = arr[i];
        }
        foodCnt[C]++;
        /* 초기 초밥 종류 */
        int l = 1, r = K;
        for (int i = l; i <= r; i++) {
            if (foodCnt[arr[i]] == 0) {
                totalCnt++;
            }
            foodCnt[arr[i]]++;
        }
        while (l <= N) {
            foodCnt[arr[l]]--;
            if (foodCnt[arr[l]] == 0) {
                totalCnt--;
            }
            l++;
            r++;
            if (foodCnt[arr[r]] == 0) {
                totalCnt++;
            }
            foodCnt[arr[r]]++;
            ans = Math.max(ans, totalCnt);
        }
        System.out.println(ans);
    }
}