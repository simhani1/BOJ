import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        long N = Long.parseLong(br.readLine());
        int M = 1000000;
        int P = 15 * M / 10;
        int[] dp = new int[P + 1];
        if (N == 0) {
            System.out.println(0);
        } else {
            dp[1] = 1;
            for (int i = 2; i < P; i++) {
                dp[i] = (dp[i - 1] + dp[i - 2]) % M;
            }
            System.out.println(dp[(int) (N % P)]);
        }
    }
}