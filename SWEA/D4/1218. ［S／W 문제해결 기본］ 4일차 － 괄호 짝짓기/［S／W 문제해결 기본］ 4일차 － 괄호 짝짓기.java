import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Solution {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, T;
    private static Deque<Character> dq;

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        for (int t = 1; t <= 10; t++) {
            N = Integer.parseInt(br.readLine());
            dq = new ArrayDeque<>();
            String str = br.readLine();
            sb.append("#")
                    .append(t)
                    .append(" ")
                    .append(solve(str))
                    .append("\n");
        }
        System.out.println(sb.toString());
    }

    private static int solve(String str) {
        for (int i = 0; i < N; i++) {
            char now = str.charAt(i);
            if (now == ')' || now == ']' || now == '}' || now == '>') {
                if (!isValid(now)) {
                    return 0;
                }
                dq.pollLast();
            } else {
                dq.addLast(now);
            }
        }
        return dq.isEmpty() ? 1 : 0;
    }

    private static boolean isValid(char target) {
        if (dq.isEmpty()) {
            return false;
        }
        switch (target) {
            case ')':
                return dq.getLast() == '(';
            case '}':
                return dq.getLast() == '{';
            case ']':
                return dq.getLast() == '[';
            case '>':
                return dq.getLast() == '<';
        }
        return true;
    }
}