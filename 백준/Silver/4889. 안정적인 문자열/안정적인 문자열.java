import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        Stack<Character> stack = new Stack<>();
        int t = 1;
        while (true) {
            char[] arr = br.readLine().toCharArray();
            if (arr[0] == '-') {
                break;
            }
            int ans = 0;
            for (int i = 0; i < arr.length; i++) {
                char c = arr[i];
                if (c == '}' && !stack.isEmpty() && stack.peek() == '{') {
                    stack.pop();
                } else {
                    stack.push(c);
                }
            }
            while (!stack.isEmpty()) {
                char c1 = stack.pop();
                char c2 = stack.pop();
                if (c1 == c2) {
                    ans++;
                } else {
                    ans += 2;
                }
            }
            sb.append(t++).append(". ").append(ans).append("\n");
        }
        System.out.println(sb);
    }

}