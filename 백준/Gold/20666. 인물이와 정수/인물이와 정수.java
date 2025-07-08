import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N, M, P;
	static long[] difficulty;
	static boolean[] visited;
	static List<Tip>[] tips;
	static Queue<Monster> pq = new PriorityQueue<>((o1, o2) -> Long.compare(o1.difficulty, o2.difficulty));

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M =	Integer.parseInt(st.nextToken());
		difficulty = new long[N + 1];
		tips = new ArrayList[N + 1];
		st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= N; i++) {
			difficulty[i] = Long.parseLong(st.nextToken());
			tips[i] = new ArrayList<>();
		}
		P = Integer.parseInt(br.readLine());
		for (int i = 0; i < P; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int t = Integer.parseInt(st.nextToken());
			tips[a].add(new Tip(b, t));
			difficulty[b] += t;
		}
		for (int i = 1; i <= N; i++) {
			pq.offer(new Monster(i, difficulty[i]));
		}
		long ans = 0;
		visited = new boolean[N + 1];
		while (M-- > 0) {
			Monster monster = pq.poll();
			while (visited[monster.num]) {
				monster = pq.poll();
			}
			visited[monster.num] = true;
			ans = Math.max(ans, monster.difficulty);
			for (Tip tip : tips[monster.num]) {
				if (!visited[tip.monster]) {
					difficulty[tip.monster] -= tip.alphaDifficulty;
					pq.offer(new Monster(tip.monster, difficulty[tip.monster]));
				}
			}
		}
		System.out.println(ans);
	}

	static class Monster {
		int num;
		long difficulty;

		public Monster(int num, long difficulty) {
			this.num = num;
			this.difficulty = difficulty;
		}
	}

	static class Tip {
		int monster;
		int alphaDifficulty;

		public Tip(int monster, int alphaDifficulty) {
			this.monster = monster;
			this.alphaDifficulty = alphaDifficulty;
		}
	}
}