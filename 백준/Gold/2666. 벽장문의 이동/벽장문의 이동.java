import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N, M;
	static int[] arr;

	public static void main(String[] args) throws IOException {
		N = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		int opened1 = Integer.parseInt(st.nextToken());
		int opened2 = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(br.readLine());
		arr = new int[M + 1];
		for (int i = 0; i < M; i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}
		System.out.println(dfs(0, opened1, opened2));
	}

	private static int dfs(int idx, int opened1, int opened2) {
		if (idx == M) return 0;
		return Math.min(
			Math.abs(arr[idx] - opened1) + dfs(idx + 1, arr[idx], opened2),
			Math.abs(arr[idx] - opened2) + dfs(idx + 1, opened1, arr[idx])
		);
	}
}

