import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static String str;
	static int N;
	static boolean[] visited;
	static String[] arr;
	static boolean flag = false;

	public static void main(String[] args) throws IOException {
		str = br.readLine();
		N = Integer.parseInt(br.readLine());
		arr = new String[N];
		visited = new boolean[str.length()];
		for (int i = 0; i < N; i++) {
			arr[i] = br.readLine();
		}
		dfs(0);
		System.out.println(flag ? 1 : 0);
	}

	private static void dfs(int idx) {
		if (idx == str.length()) {
			flag = true;
			return;
		}
		for (String word : arr) {
			if (str.startsWith(word, idx) && !visited[idx + word.length() - 1]) {
				visited[idx + word.length() - 1] = true;
				dfs(idx + word.length());
			}
		}
	}
}
