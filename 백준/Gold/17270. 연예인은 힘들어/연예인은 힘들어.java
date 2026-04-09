import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	static int V, M;
	static int[][] dist;
	static final int INF = 99999;

	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(br.readLine());
		V = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		dist = new int[V + 1][V + 1];
		for (int i = 0; i <= V; i++) {
			for (int j = 0; j <= V; j++) {
				dist[i][i] = 0;
				dist[i][j] = INF;
			}
		}
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			dist[a][b] = Math.min(dist[a][b], c);
			dist[b][a] = Math.min(dist[b][a], c);
		}

		st = new StringTokenizer(br.readLine());
		int J = Integer.parseInt(st.nextToken());
		int S = Integer.parseInt(st.nextToken());

		for (int k = 1; k <= V; k++) {
			for (int i = 1; i <= V; i++) {
				for (int j = 1; j <= V; j++) {
					if (i == j) continue;
					if (dist[i][k] == INF || dist[k][j] == INF) continue;
					dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		int minTime = INF;
		for (int j = 1; j <= V; j++) {
			if (j == J || j == S || dist[J][j] == INF || dist[j][S] == INF)
				continue;
			minTime = Math.min(minTime, dist[J][j] + dist[j][S]);
		}

		int ans = -1;
		int minJTime = INF;
		for (int j = 1; j <= V; j++) {
			if (j == J || j == S || dist[J][j] == INF || dist[j][S] == INF)
				continue;
			if (dist[J][j] <= dist[j][S] &&
				dist[J][j] + dist[j][S] == minTime &&
				dist[J][j] < minJTime) {
				minJTime = dist[J][j];
				ans = j;
			}
		}

		System.out.println(ans);
	}
}