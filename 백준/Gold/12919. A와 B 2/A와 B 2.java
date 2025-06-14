import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static String S, T;
    static Set<String> set = new HashSet<>();
    static int ans = 0;

    public static void main(String[] args) throws IOException {
        S = br.readLine();
        T = br.readLine();
        System.out.println(bfs() ? 1 : 0);
    }

    private static boolean bfs() {
        Queue<String> q = new ArrayDeque<>();
        q.offer(T);
        while (!q.isEmpty()) {
            String now = q.poll();
            if (now.equals(S)) {
                return true;
            }
            if (set.contains(now) || now.length() == S.length()) {
                continue;
            }
            set.add(now);
            int lastIdx = now.length() - 1;
            if (now.charAt(lastIdx) == 'A') {
                q.offer(now.substring(0, lastIdx));
            }
            if (now.charAt(0) == 'B') {
                StringBuilder tmp = new StringBuilder(now).reverse();
                q.offer(tmp.substring(0, lastIdx));
            }
        }
        return false;
    }
}
