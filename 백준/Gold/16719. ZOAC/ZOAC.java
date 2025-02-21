import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static String str;
    private static boolean[] visited;

    public static void main(String[] args) throws Exception {
        str = br.readLine();
        visited = new boolean[str.length()];
        dfs(0, str.length() - 1);
        System.out.println(sb);
    }

    private static void dfs(int l, int r) {
        if (l > r) {
            return;
        }
        int idx = l;
        for (int i = l; i <= r; i++) {
            if (str.charAt(idx) > str.charAt(i)) {
                idx = i;
            }
        }
        visited[idx] = true;
        for (int i = 0; i < str.length(); i++) {
            if (visited[i]) {
                sb.append(str.charAt(i));
            }
        }
        sb.append("\n");
        dfs(idx + 1, r);
        dfs(l, idx - 1);
    }
}