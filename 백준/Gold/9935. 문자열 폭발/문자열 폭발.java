import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static String parent, pattern;
    private static Stack<Character> stack = new Stack<>();

    public static void main(String[] args) throws IOException {
        parent = br.readLine();
        pattern = br.readLine();
        for (int i = 0; i < parent.length(); i++) {
            stack.push(parent.charAt(i));
            /* pattern이 발견될 수 있는 상태 */
            /*
            * 5
            * 3
            * 2 3 4
            * */
            if (stack.size() >= pattern.length()) {
                boolean flag = true;
                for (int j = 0; j < pattern.length(); j++) {
                    if (stack.get(stack.size() - pattern.length() + j) != pattern.charAt(j)) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    for (int j = 0; j < pattern.length(); j++) {
                        stack.pop();
                    }
                }
            }
        }
        if (stack.isEmpty()) {
            System.out.println("FRULA");
        } else {
            while (!stack.isEmpty()) {
                sb.append(stack.pop());
            }
            System.out.println(sb.reverse().toString());
        }
    }
}