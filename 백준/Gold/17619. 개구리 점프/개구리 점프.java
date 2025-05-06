import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int N, Q;
    static int[] parent;
    static Node[] arr;

    static class Node {
        int num;
        int l;
        int r;

        public Node(int num, int l, int r) {
            this.num = num;
            this.l = l;
            this.r = r;
        }

        @Override
        public String toString() {
            return "Node{" +
                "num=" + num +
                ", l=" + l +
                ", r=" + r +
                '}';
        }
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());
        parent = new int[N];
        arr = new Node[N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            arr[i] = new Node(i, l, r);
            parent[i] = i;
        }
        Arrays.sort(arr, (o1, o2) -> {
            if (o1.l == o2.l) {
                return Integer.compare(o1.r, o2.r);
            }
            return Integer.compare(o1.l, o2.l);
        });
        int prevL = arr[0].l;
        int prevR = arr[0].r;
        for (int i = 1; i < N; i++) {
            int nowL = arr[i].l;
            int nowR = arr[i].r;
            int num = arr[i].num;
            if (prevL <= nowL && nowL <= prevR) {
                parent[num] = find(arr[i - 1].num);
                prevR = Math.max(prevR, nowR);
            } else {
                prevL = nowL;
                prevR = nowR;
            }
        }
        for (int i = 0; i < Q; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken()) - 1;
            int to = Integer.parseInt(st.nextToken()) - 1;
            sb.append(parent[from] == parent[to] ? 1 : 0).append("\n");
        }
        System.out.println(sb);
    }

    private static int find(int a) {
        if (parent[a] == a) {
            return a;
        }
        return parent[a] = find(parent[a]);
    }
}