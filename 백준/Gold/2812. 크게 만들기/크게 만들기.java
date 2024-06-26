import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N, K;
    private static String num;
    private static Stack<Integer> stack = new Stack<>();

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        num = br.readLine();

        stack.add(num.charAt(0) - '0');

        for (int i = 1; i < num.length(); i++) {
            int now = num.charAt(i) - '0';
            while (K > 0 && !stack.isEmpty()) {
                if (stack.peek() >= now) {
                    break;
                }
                stack.pop();
                K--;
            }
            stack.add(now);
        }
        while (K > 0 && !stack.isEmpty()) {
            stack.pop();
            K--;
        }
        while (!stack.isEmpty()) {
            sb.append(stack.pop());
        }
        System.out.println(sb.reverse());
    }

}