import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int A, B, C;
    static String X, Y;
    static int[][] dp;
    static int INF = -987654321;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        A =  Integer.parseInt(st.nextToken());
        B =  Integer.parseInt(st.nextToken());
        C =  Integer.parseInt(st.nextToken());
        X = br.readLine();
        Y = br.readLine();
        dp = new int[X.length() + 1][Y.length() + 1];
        for (int i = 0; i <= X.length(); i++) {
            for (int j = 0; j <= Y.length(); j++) {
                dp[i][j] = INF;
            }
        }
        System.out.println(dfs(0, 0));
    }

    private static int dfs(int idx1, int idx2) {
        if (idx1 == X.length() && idx2 == Y.length()) {
            return 0;
        }
        if (dp[idx1][idx2] != INF) {
            return dp[idx1][idx2];
        }
        int score = INF;
        if (idx1 < X.length() && idx2 < Y.length()) {
            score = Math.max(score, dfs(idx1 + 1, idx2 + 1) + (X.charAt(idx1) == Y.charAt(idx2) ? A : C));
        }
        if (idx1 < X.length()) {
            score = Math.max(score, dfs(idx1 + 1, idx2) + B);
        }
        if (idx2 < Y.length()) {
            score = Math.max(score, dfs(idx1, idx2 + 1) + B);
        }
        return dp[idx1][idx2] = score;
    }
}
