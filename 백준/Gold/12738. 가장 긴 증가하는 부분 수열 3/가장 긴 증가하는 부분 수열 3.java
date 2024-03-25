import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StringWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N, ans = 0;
    private static int[] arr, dp;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        arr = new int[N + 1];
        dp = new int[N + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        int len = 1;
        dp[0] = arr[0];
        for (int i = 1; i < N; i++) {
            if (dp[len - 1] < arr[i]) {
                dp[len++] = arr[i];
            } else if (dp[len - 1] > arr[i]) {
                int idx = binarySearch(0, len - 1, arr[i]);
                dp[idx] = arr[i];
            }
        }
        System.out.println(len);
    }

    private static int binarySearch(int l, int r, int target) {
        int mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (dp[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

}