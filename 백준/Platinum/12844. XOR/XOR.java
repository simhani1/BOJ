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
		tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
	}

	static void propagate(int node, int nodeL, int nodeR) {
		if (lazy[node] != 0) {
			if ((nodeR - nodeL + 1) % 2 == 1) {
				tree[node] ^= lazy[node];
			}
			if (nodeL != nodeR) {
				lazy[node * 2] ^= lazy[node];
				lazy[node * 2 + 1] ^= lazy[node];
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
			lazy[node] ^= val;
			propagate(node, nodeL, nodeR);
			return;
		}
		int mid = (nodeL + nodeR) / 2;
		update(node * 2, nodeL, mid, left, right, val);
		update(node * 2 + 1, mid + 1, nodeR, left, right, val);
		tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
	}

	static long query(int node, int nodeL, int nodeR, int left, int right) {
		propagate(node, nodeL, nodeR);
		if (right < nodeL || nodeR < left) {
			return 0;
		}
		if (left <= nodeL && nodeR <= right) {
			return tree[node];
		}
		int mid = (nodeL + nodeR) / 2;
		long leftVal = query(node * 2, nodeL, mid, left, right);
		long rightVal = query(node * 2 + 1, mid + 1, nodeR, left, right);
		return leftVal ^ rightVal;
	}

	static long query(int left, int right) {
		return query(1, 1, N, left, right);
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
		init(1, 1, N);
		M = Integer.parseInt(br.readLine());
		for (int i = 1; i <= M; i++) {
			st = new StringTokenizer(br.readLine());
			int a =  Integer.parseInt(st.nextToken());
			int l = Integer.parseInt(st.nextToken()) + 1;
			int r = Integer.parseInt(st.nextToken()) + 1;
			if (a == 1) {
				long k = Long.parseLong(st.nextToken());
				update(l, r, k);
			} else {
				sb.append(query(l, r)).append("\n");
			}
		}
		System.out.println(sb);
	}
}
