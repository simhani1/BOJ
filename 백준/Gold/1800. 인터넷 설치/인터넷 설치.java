import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	private static final int INF = 987654321;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N, P, K;
	static List<Edge>[] edges;
	static int[] cnt;

	static class Edge {
		int to, cost;

		public Edge(int to, int cost) {
			this.to = to;
			this.cost = cost;
		}
	}

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		P = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		cnt = new int[N + 1];
		edges = new ArrayList[N + 1];
		for (int i = 0; i <= N; i++) {
			edges[i] = new ArrayList<>();
		}
		for (int i = 0; i < P; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			edges[a].add(new Edge(b, c));
			edges[b].add(new Edge(a, c));
		}
		int l = 0, r = 1_000_000;
		int ret = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (check(mid)) {
				ret = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		System.out.println(ret);
	}

	private static boolean check(int mid) {
		Queue<Edge> pq = new PriorityQueue<>((o1, o2) -> Integer.compare(o1.cost, o2.cost));
		pq.offer(new Edge(1, 0));
		for (int i = 1; i <= N; i++) {
			cnt[i] = INF;
		}
		while (!pq.isEmpty()) {
			Edge edge = pq.poll();
			int now = edge.to;
			int nowCnt = edge.cost;
			for (int i = 0; i < edges[now].size(); i++) {
				int nextCnt = 0;
				int next = edges[now].get(i).to;
				int nextCost = edges[now].get(i).cost;
				nextCnt = nextCost > mid ? nowCnt + 1 : nowCnt;
				if (cnt[next] > nextCnt) {
					cnt[next] = nextCnt;
					pq.offer(new Edge(next, nextCnt));
				}
			}
		}
		return cnt[N] <= K;  // mid보다 큰 간선을 K개 이하 사용하여 N번 노드에 방문 가능하다면 정답
	}
}
