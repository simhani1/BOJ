import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();

    static class Node {
        int num;
        Node left;
        Node right;

        public Node(int num, Node left, Node right) {
            this.num = num;
            this.left = left;
            this.right = right;
        }

        private void insert(int target) {
            if (this.num > target) {
                if (this.left == null) {
                    this.left = new Node(target, null, null);
                } else {
                    this.left.insert(target);
                }
            } else {
                if (this.right == null) {
                    this.right = new Node(target, null, null);
                } else {
                    this.right.insert(target);
                }
            }
        }

        @Override
        public String toString() {
            return "Node{" +
                    "num=" + num +
                    ", left=" + left +
                    ", right=" + right +
                    '}';
        }
    }

    public static void main(String[] args) throws Exception {
        Node root = new Node(Integer.parseInt(br.readLine()), null, null);
        String num = null;
        while (true) {
            num = br.readLine();
            if (num == null || num.equals("")) {
                break;
            }
            root.insert(Integer.parseInt(num));
        }
        solve(root);
        System.out.println(sb);
    }

    private static void solve(Node node) {
        if (node == null) {
            return;
        }
        solve(node.left);
        solve(node.right);
        sb.append(node.num).append("\n");
    }
}