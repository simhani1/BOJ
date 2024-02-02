import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, T;
    private static Deque<Integer> dq = new ArrayDeque<>();

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        for (int i = N; i >= 1; i--) {
            dq.addLast(i);
        }
        System.out.println(solve());
    }

    private static int solve() {
        while (dq.size() != 1) {
            dq.pollLast();
            dq.addFirst(dq.pollLast());
        }
        return dq.pollLast();
    }
}