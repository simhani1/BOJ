import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N, S, D, ans = 0;
	static List<Integer>[] edges;
	static int[] dist;

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		S = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());
		dist = new int[N + 1];
		edges = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++) {
			edges[i] = new ArrayList<>();
		}
		for (int i = 0; i < N - 1; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			edges[x].add(y);
			edges[y].add(x);
		}
		dfs(S, 0);
		System.out.println(ans * 2);
	}

	private static int dfs(int now, int parent) {
		for (int child : edges[now]) {
			if (child != parent) {
				dist[now] = Math.max(dist[now], dfs(child, now) + 1);
			}
		}
		if (now != S && dist[now] >= D) {
			ans++;
		}
		return dist[now];
	}
}