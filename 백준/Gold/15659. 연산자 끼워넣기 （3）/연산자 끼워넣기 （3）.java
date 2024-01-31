import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N;
    private static int maxAns = Integer.MIN_VALUE, minAns = Integer.MAX_VALUE;
    private static int[] arr = new int[15];
    private static char[] op = new char[15];
    private static int[] operator = new int[4];  // + - * /

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 4; i++) {
            operator[i] = Integer.parseInt(st.nextToken());
        }
        solve(1);
        System.out.println(maxAns + "\n" + minAns);
    }

    private static void solve(int idx) {
        if (idx == N) {
            calc();
            return;
        }
        for (int i = 0; i < 4; i++) {
            if (operator[i] <= 0) {
                continue;
            }
            operator[i]--;
            if (i == 0) {
                op[idx] = '+';
            } else if (i == 1) {
                op[idx] = '-';
            } else if (i == 2) {
                op[idx] = '*';
            } else if (i == 3) {
                op[idx] = '/';
            }
            solve(idx + 1);
            operator[i]++;
        }
    }

    private static void calc() {
        Deque<Integer> dqNum = new ArrayDeque<>();
        Deque<Character> dqOp = new ArrayDeque<>();
        dqNum.add(arr[0]);
        for (int i = 1; i < N; i++) {
            int num2 = arr[i];
            if (op[i] == '*') {
                int num1 = dqNum.pollLast();
                dqNum.addLast(num1 * num2);
                continue;
            }
            if (op[i] == '/') {
                int num1 = dqNum.pollLast();
                dqNum.addLast(num1 / num2);
                continue;
            }
            dqNum.addLast(num2);
            dqOp.addLast(op[i]);
        }
        while (dqNum.size() != 1) {
            int num1 = dqNum.pollFirst();
            int num2 = dqNum.pollFirst();
            char operator = dqOp.pollFirst();
            if (operator == '+') {
                dqNum.addFirst(num1 + num2);
            } else {
                dqNum.addFirst(num1 - num2);
            }
        }
        int sum = dqNum.pollFirst();
        maxAns = Math.max(maxAns, sum);
        minAns = Math.min(minAns, sum);
    }
}