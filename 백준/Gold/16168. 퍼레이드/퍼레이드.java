import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int V, E;
    private static int[] edge = new int[3001];
    private static int[] parent = new int[3001];

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= V; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            edge[A]++;
            edge[B]++;
            Union(A, B);
        }
        int oddEdge = 0;
        int root = Find(1);
        for (int i = 1; i <= V; i++) {
            if (root != Find(i)) {
                System.out.println("NO");
                return;
            }
            if (edge[i] % 2 == 1) {
                oddEdge++;
            }
        }
        if (oddEdge == 2 || oddEdge == 0) {
            System.out.println("YES");
            return;
        }
        System.out.println("NO");
    }

    private static void Union(int A, int B) {
        A = Find(A);
        B = Find(B);
        parent[Math.max(A, B)] = Math.min(A, B);
    }

    private static int Find(int A) {
        if (parent[A] == A) {
            return A;
        }
        return parent[A] = Find(parent[A]);
    }
}