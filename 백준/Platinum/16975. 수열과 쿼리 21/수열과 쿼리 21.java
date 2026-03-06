import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	static int N, M;
	static long[] arr, tree, lazy;

	static void init(int node, int nodeL, int nodeR) {
		if (nodeL == nodeR) {
			tree[node] = arr[nodeL];
			return;
		}
		int mid = (nodeL + nodeR) / 2;
		init(node * 2, nodeL, mid);
		init(node * 2 + 1, mid + 1, nodeR);
	}

	static void propagate(int node, int nodeL, int nodeR) {
		if (lazy[node] != 0) {
			tree[node] += (nodeR - nodeL + 1) * lazy[node];
			if (nodeL != nodeR) {
				lazy[node * 2] += lazy[node];
				lazy[node * 2 + 1] += lazy[node];
			}
			lazy[node] = 0;
		}
	}

	static void update(int node, int nodeL, int nodeR, int left, int right, long val) {
		propagate(node, nodeL, nodeR);
		if (right < nodeL || nodeR < left) {
			return;
		}
		if (left <= nodeL && nodeR <= right) {
			lazy[node] += val;
			propagate(node, nodeL, nodeR);
			return;
		}
		int mid = (nodeL + nodeR) / 2;
		update(node * 2, nodeL, mid, left, right, val);
		update(node * 2 + 1, mid + 1, nodeR, left, right, val);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}

	static void query(int node, int nodeL, int nodeR, int idx) {
		propagate(node, nodeL, nodeR);
		if (idx < nodeL || nodeR < idx) {
			return;
		}
		if (nodeL == nodeR) {
			sb.append(tree[node]).append("\n");
			return;
		}
		int mid = (nodeL + nodeR) / 2;
		query(node * 2, nodeL, mid, idx);
		query(node * 2 + 1, mid + 1, nodeR, idx);
	}

	static void query(int idx) {
		query(1, 1, N, idx);
	}

	static void update(int left, int right, long val) {
		update(1, 1, N, left, right, val);
	}

	public static void main(String[] args) throws Exception {
		N = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		arr = new long[N + 1];
		lazy = new long[4 * N];
		tree = new long[4 * N];
		for (int i = 1; i <= N; i++) {
			arr[i] = Long.parseLong(st.nextToken());
		}
		M = Integer.parseInt(br.readLine());
		init(1, 1, N);
		for (int i = 1; i <= M; i++) {
			st = new StringTokenizer(br.readLine());
			int a =  Integer.parseInt(st.nextToken());
			if (a == 1) {
				int l = Integer.parseInt(st.nextToken());
				int r = Integer.parseInt(st.nextToken());
				long k = Long.parseLong(st.nextToken());
				update(l, r, k);
			} else {
				int idx = Integer.parseInt(st.nextToken());
				query(idx);
			}
		}
		System.out.println(sb);
	}
}
