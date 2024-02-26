import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static int N, M;
	private static int[] parent;

	private static void Union(int a, int b) {
		a = Find(a);
		b = Find(b);
		if (a != b) {
			parent[Math.max(a, b)] = Math.min(a, b);
		}
	}

	private static int Find(int a) {
		if (parent[a] == a)
			return a;
		return parent[a] = Find(parent[a]);
	}

	public static void main(String[] args) throws IOException {

		N = Integer.parseInt(br.readLine());
		M = Integer.parseInt(br.readLine());

		parent = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			parent[i] = i;
		}
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int A = Integer.parseInt(st.nextToken());
			int B = Integer.parseInt(st.nextToken());
			Union(A, B);
		}
		int ans = 0;
		for (int i = 2; i <= N; i++) {
			if (Find(i) == 1) {
				ans++;
			}
		}
		System.out.println(ans);
	}
}