import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int L;
    private static String target, heaven, hell;
    private static char[][] arr;
    private static int[][][] dp;

    public static void main(String[] args) throws Exception {
        target = br.readLine();
        heaven = br.readLine();
        hell = br.readLine();
        L = heaven.length();
        arr = new char[2][L];
        dp = new int[2][L][target.length()];
        /* init */
        arr[0] = heaven.toCharArray();
        arr[1] = hell.toCharArray();
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < L; j++) {
                if (arr[i][j] == target.charAt(0)) {
                    dp[i][j][0] = 1;
                }
            }
        }
        /* solve */
        for (int idx = 1; idx < target.length(); idx++) {
            char now = target.charAt(idx);
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < L; j++) {
                    if (arr[i][j] == now) {
                        for (int k = 0; k < j; k++) {
                            if (arr[(i + 1) % 2][k] == target.charAt(idx - 1)) {
                                dp[i][j][idx] += dp[(i + 1) % 2][k][idx - 1];
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < L; j++) {
                if (arr[i][j] == target.charAt(target.length() - 1)) {
                    ans += dp[i][j][target.length() - 1];
                }
            }
        }
        System.out.println(ans);
    }
}