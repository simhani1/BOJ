import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N;
	static String str;
	static Stack<Integer> stack = new Stack<>();

	public static void main(String[] args) throws IOException {
		N = Integer.parseInt(br.readLine());
		str = br.readLine();
		int ret = 0;
		for (int i = 0; i < N; i++) {
			if (str.charAt(i) == 's') {
				stack.push(1);
			} else if (str.charAt(i) == 'k') {
				if (!stack.isEmpty() && stack.peek() == 1) {
					stack.push(stack.pop() + 1);
				} else {
					stack.clear();
				}
			} else if (str.charAt(i) == 'e') {
				if (!stack.isEmpty() && (stack.peek() == 2 || stack.peek() == 3)) {
					stack.push(stack.pop() + 1);
				} else {
					stack.clear();
				}
			} else if (str.charAt(i) == 'p') {
				if (!stack.isEmpty() && stack.peek() == 4) {
					stack.push(stack.pop() + 1);
				} else {
					stack.clear();
				}
			} else {
				stack.clear();
			}
			while (!stack.isEmpty() && stack.peek() == 5) {
				ret++;
				stack.pop();
				if (!stack.isEmpty()) {
					stack.push(stack.pop() + 1);
				}
			}
		}
		System.out.println(ret);
	}
}
