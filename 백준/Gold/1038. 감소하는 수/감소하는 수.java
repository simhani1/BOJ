import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	static List<Long> list = new ArrayList<>();

	public static void main(String[] args) throws Exception {
		// 9_876_543_210 10자리가 최대
		for (int i = 0; i <= 10; i++) {
			dfs(0, 0, i);
		}
		int N = Integer.parseInt(br.readLine());
		if (N < list.size()) {
			System.out.println(list.get(N));
		} else {
			System.out.println(-1);
		}
	}

	static void dfs(long num, int len, int maxLen) {
		if (len == maxLen) {
			list.add(num);
			return;
		}
		long start = num == 0 ? 1 : 0;
		long max = num == 0 ? 10 : num % 10;
		for (long i = start; i < max; i++) {
			dfs(num * 10 + i, len + 1, maxLen);
		}
	}
}