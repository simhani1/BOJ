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
	static int T, N, M;
	static List<Edge>[] edges;
	static final int INF = Integer.MAX_VALUE;

	static class Edge {
		int num, cost;

		public Edge(int num, int cost) {
			this.num = num;
			this.cost = cost;
		}

		@Override
		public String toString() {
			return "Edge{" +
				"next=" + num +
				", cost=" + cost +
				'}';
		}
	}

	public static void main(String[] args) throws IOException {
		T = Integer.parseInt(br.readLine());
		while (T-- > 0) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			edges = new ArrayList[N + 1];
			for (int i = 1; i <= N; i++) {
				edges[i] = new ArrayList<>();
			}
			for (int i = 0; i < M; i++) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				int c = Integer.parseInt(st.nextToken());
				edges[a].add(new Edge(b, c));
				edges[b].add(new Edge(a, c));
			}
			int ans = dfs(1, 0, INF);
			sb.append(ans != INF ? ans : 0).append("\n");
		}
		System.out.println(sb);
	}

	private static int dfs(int now, int parent, int cost) {
		int ret = 0;
		for (Edge edge : edges[now]) {
			if (edge.num != parent) {
				ret += dfs(edge.num, now, edge.cost);
			}
		}
		if (ret == 0) {
			ret = cost;
		}
		return Math.min(ret, cost);
	}
}