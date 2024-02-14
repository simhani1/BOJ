import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static long A, B, C;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        System.out.println(solve(B));
    }

    private static long solve(long b) {
        if (b == 0) {
            return 1;
        } else if (b == 1) {
            return A % C;
        }
        long tmp = solve(b / 2);
        if (b % 2 == 0) {
            return ((tmp % C) * (tmp % C)) % C;
        } else {
            return (A * (((tmp % C) * (tmp % C)) % C)) % C;
        }
    }
}