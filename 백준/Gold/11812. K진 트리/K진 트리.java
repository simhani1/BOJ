import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static long N, K, Q;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Long.parseLong(st.nextToken());
        K = Long.parseLong(st.nextToken());
        Q = Long.parseLong(st.nextToken());
        while (Q-- > 0) {
            st = new StringTokenizer(br.readLine());
            long x = Long.parseLong(st.nextToken());
            long y = Long.parseLong(st.nextToken());
            sb.append(lca(x, y)).append("\n");
        }
        System.out.println(sb);
    }

    private static long lca(long x, long y) {
        if (K == 1) {
            return Math.abs(x - y);
        }
        long dist = 0;
        while (x != y) {
            if (x > y) {
                x = getParent(x);
            } else {
                y = getParent(y);
            }
            dist++;
        }
        return dist;
    }

    private static long getParent(long child) {
        return (child - 2) / K + 1;
    }
}