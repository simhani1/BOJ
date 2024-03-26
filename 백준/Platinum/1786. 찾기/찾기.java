import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;

    private static int[] failureFunc(String pattern) {
        int[] failure = new int[pattern.length()];
        int j = 0;
        for (int i = 1; i < pattern.length(); i++) {
            while (j > 0 && pattern.charAt(i) != pattern.charAt(j)) {
                j = failure[j - 1];
            }
            if (pattern.charAt(i) == pattern.charAt(j)) {
                failure[i] = ++j;
            }
        }
        return failure;
    }

    static void kmp(String parent, String pattern) {
        int ans = 0;
        int[] failure = failureFunc(pattern);
        int j = 0;
        for (int i = 0; i < parent.length(); i++) {
            while (j > 0 && parent.charAt(i) != pattern.charAt(j)) {
                j = failure[j - 1];
            }
            if (parent.charAt(i) == pattern.charAt(j)) {
                if (j == pattern.length() - 1) {
                    ans++;
                    sb.append(i - j + 1).append(" ");
                    j = failure[j];
                } else {
                    j++;
                }
            }
        }
        System.out.println(ans);
        System.out.println(sb.toString());
    }

    public static void main(String[] args) throws IOException {
        String parent = br.readLine();
        String pattern = br.readLine();
        kmp(parent, pattern);
    }
}