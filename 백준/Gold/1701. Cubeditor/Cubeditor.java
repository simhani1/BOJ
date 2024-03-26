import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;

    private static int failureFunc(String pattern) {
        int maxLen = 0;
        int[] failure = new int[pattern.length()];
        int j = 0;
        for (int i = 1; i < pattern.length(); i++) {
            while (j > 0 && pattern.charAt(i) != pattern.charAt(j)) {
                j = failure[j - 1];
            }
            if (pattern.charAt(i) == pattern.charAt(j)) {
                failure[i] = ++j;
                maxLen = Math.max(maxLen, failure[i]);
            }
        }
        return maxLen;
    }

    public static void main(String[] args) throws IOException {
        String parent = br.readLine();
        int ans = 0;
        for (int i = 0; i < parent.length(); i++) {
            ans = Math.max(ans, failureFunc(parent.substring(i, parent.length())));
        }
        System.out.println(ans);
    }
}