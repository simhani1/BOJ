import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N;
    private static String str1, str2, str3;
    private static boolean[][] visited;

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            str1 = st.nextToken();
            str2 = st.nextToken();
            str3 = st.nextToken();
            visited = new boolean[str1.length() + 1][str2.length() + 1];
            dfs(0, 0, 0);
            sb.append(visited[str1.length()][str2.length()] ? successMsg(i) : failMsg(i)).append("\n");
        }
        System.out.println(sb);
    }

    private static void dfs(int idx1, int idx2, int idx3) {
        if (visited[idx1][idx2]) {
            return;
        }
        visited[idx1][idx2] = true;
        if (idx1 < str1.length() && str1.charAt(idx1) == str3.charAt(idx3)) {
            dfs(idx1 + 1, idx2, idx3 + 1);
        }
        if (idx2 < str2.length() && str2.charAt(idx2) == str3.charAt(idx3)) {
            dfs(idx1, idx2 + 1, idx3 + 1);
        }
    }

    private static String failMsg(int num) {
        return "Data set " + num + ": no";
    }

    private static String successMsg(int num) {
        return "Data set " + num + ": yes";
    }
}