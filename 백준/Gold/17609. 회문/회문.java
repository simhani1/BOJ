import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int T;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            String str = br.readLine();
            sb.append(solve(str, 0, str.length() - 1, 0)).append("\n");
        }
        System.out.println(sb);
    }

    private static int solve(String str, int l, int r, int cnt) {
        while (l < r) {
            if (str.charAt(l) == str.charAt(r)) {
                l++;
                r--;
                continue;
            }
            if (cnt == 0) {
                if (solve(str, l, r - 1, cnt + 1) == 0 ||
                    solve(str, l + 1, r, cnt + 1) == 0) {
                    return 1;
                }
                return 2;
            } else {
                return 2;
            }
        }
        return 0;
    }
}