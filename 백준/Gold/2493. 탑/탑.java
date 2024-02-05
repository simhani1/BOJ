import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, T;
    private static int[] arr = new int[500001];
    private static Stack<Pair> stack = new Stack<>();

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken());
        stack.push(new Pair(0, start));
        for (int i = 1; i < N; i++) {
            int now = Integer.parseInt(st.nextToken());
            while (stack.peek().num <= now) {
                stack.pop();
                if (stack.isEmpty()) {
                    break;
                }
            }
            if (stack.isEmpty()) {
                arr[i] = 0;
                stack.push(new Pair(i, now));
            } else {
                arr[i] = stack.peek().idx + 1;
                stack.push(new Pair(i, now));
            }
        }
        for (int i = 0; i < N; i++) {
            sb.append(arr[i])
                    .append(" ");
        }
        System.out.println(sb.toString());
    }
}

class Pair {
    int idx;
    int num;

    public Pair(int idx, int num) {
        this.idx = idx;
        this.num = num;
    }
}