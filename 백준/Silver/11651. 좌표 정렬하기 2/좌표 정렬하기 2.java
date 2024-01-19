import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        List<Node> nodes = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            nodes.add(new Node(x, y));
        }

        nodes.sort(new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                if (o1.y == o2.y) {
                    return o1.x - o2.x;
                }
                return o1.y - o2.y;
            }
        });

        // solve
        StringBuilder sb = new StringBuilder();
        for (Node node : nodes) {
            sb.append(node.x + " " + node.y + "\n");
        }
        System.out.println(sb.toString());
    }
}

class Node {

    int x;
    int y;

    Node(int x, int y) {
        this.x = x;
        this.y = y;
    }
}