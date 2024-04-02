import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static final int MOD = 1000000000;
    private static Map<Long, Long> m = new HashMap<>();

    public static void main(String[] args) throws IOException {
        long A, B;
        st = new StringTokenizer(br.readLine());
        A = Long.parseLong(st.nextToken());
        B = Long.parseLong(st.nextToken());
        m.put(1L, 1L);
        m.put(2L, 1L);
        m.put(3L, 2L);
        m.put(4L, 3L);
        m.put(5L, 5L);
        System.out.println((fibo(B + 2) - fibo(A + 1) + MOD) % MOD);
    }

    private static long fibo(long num) {
        if (m.containsKey(num)) {
            return m.get(num);
        } else {
            if (num % 2 == 1) {
                m.put(num, (fibo(num / 2) * fibo(num / 2) + fibo(num / 2 + 1) * fibo(num / 2 + 1)) % MOD);
            } else {
                m.put(num, (fibo(num + 1) - fibo(num - 1) + MOD) % MOD);
            }
            return m.get(num);
        }
    }
}