import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	private static final int INF = 987654321;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N, M;
	static int[] inDegree, outDegree;
	static int[] dist;
	static List<Edge>[] edges;
	static int[] parent;

	static class Edge {
		int to, cost;

		public Edge(int to, int cost) {
			this.to = to;
			this.cost = cost;
		}
	}


	public static void main(String[] args) throws IOException {
		N = Integer.parseInt(br.readLine());
		M = Integer.parseInt(br.readLine());
		dist = new int[N + 1];
		parent = new int[N + 1];
		inDegree = new int[N + 1];
		outDegree = new int[N + 1];
		edges = new ArrayList[N + 1];
		for (int i = 0; i <= N; i++) {
			edges[i] = new ArrayList<>();
			parent[i] = i;
		}
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int p = Integer.parseInt(st.nextToken());
			int q = Integer.parseInt(st.nextToken());
			int r = Integer.parseInt(st.nextToken());
			edges[p].add(new Edge(q, r));
			outDegree[p]++;
			inDegree[q]++;
		}
		solve();
        
		Stack<Integer> stack = new Stack<>();
		int idx = 1;
		stack.add(idx);
		while (true) {
			idx = parent[idx];
			stack.add(idx);
			if (idx == 1) break;
		}
		sb.append(dist[1]).append("\n");
		while (!stack.isEmpty()) {
			sb.append(stack.pop()).append(" ");
		}
		System.out.println(sb);
	}


	private static void solve() {
		Queue<Integer> q = new ArrayDeque<>();
		q.offer(1);
		while (!q.isEmpty()) {
			int now = q.poll();
			if (outDegree[now] == 0) {
				continue;
			}
			for (Edge edge : edges[now]) {
				int next = edge.to;
				int cost = edge.cost;
				outDegree[now]--;
				inDegree[next]--;
				if (dist[next] < dist[now] + cost) {
					parent[next] = now;
					dist[next] = dist[now] + cost;
				}
				if (inDegree[next] == 0) {
					q.offer(next);
				}
			}
		}
	}
}
