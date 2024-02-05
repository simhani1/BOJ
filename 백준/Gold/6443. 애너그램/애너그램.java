import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, M;
    private static int[] visited;

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            M = str.length();
            visited = new int[26];
            // 알파벳 개수 저장
            for (int j = 0; j < M; j++) {
                visited[str.charAt(j) - 'a']++;
            }
            solve(str, "");
        }
        System.out.println(sb.toString());
    }

    private static void solve(String str, String target) {
        if (target.length() == M) {
            sb.append(target).append("\n");
            return;
        }
        for (int i = 0; i < 26; i++) {
            if (visited[i] > 0) {
                visited[i]--;
                solve(str, target + (char) (i + 'a'));
                visited[i]++;
            }
        }
    }
}