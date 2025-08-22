import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static String str;
	static boolean[] removed = new boolean[201];
	static Stack<Integer> stack = new Stack<>();
	static List<Bracket> brackets = new ArrayList<>();
	static TreeSet<String> set = new TreeSet<>();

	static class Bracket {
		int l;
		int r;

		public Bracket(int l, int r) {
			this.l = l;
			this.r = r;
		}
	}

	public static void main(String[] args) throws IOException {
		str = br.readLine();

		for (int i = 0; i < str.length(); i++) {
			if (str.charAt(i) == '(') {
				stack.push(i);
			} else if (str.charAt(i) == ')') {
				brackets.add(new Bracket(stack.pop(), i));
			}
		}
		dfs(0);
		for (String s : set) {
			if (!s.equals(str)) {
				sb.append(s).append("\n");
			}
		}
		System.out.println(sb);
	}

	private static void dfs(int depth) {
		if (depth == brackets.size()) {
			StringBuilder tmp = new StringBuilder();
			for (int i = 0; i < str.length(); i++) {
				if (!removed[i]) {
					tmp.append(str.charAt(i));
				}
			}
			set.add(tmp.toString());
			return;
		}

		removed[brackets.get(depth).l] = true;
		removed[brackets.get(depth).r] = true;
		dfs(depth + 1);

		removed[brackets.get(depth).l] = false;
		removed[brackets.get(depth).r] = false;
		dfs(depth + 1);
	}

}