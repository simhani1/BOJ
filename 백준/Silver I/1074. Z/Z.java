import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, R, C, num = -1;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        N = (int) Math.pow(2, N);
        solve(0, 0, N);
    }

    private static void solve(int x, int y, int size) {
        if (size == 2) {
            for (int i = x; i < x + size; i++) {
                for (int j = y; j < y + size; j++) {
                    num++;
                    if (i == R && j == C) {
                        System.out.println(num);
                        return;
                    }
                }
            }
            return;
        }
        /* 현재 탐색하는 범위에 속한다면 */
        if (x <= R && R < x + size && y <= C && C < y + size) {
            int nextSize = size / 2;
            solve(x, y, nextSize);
            solve(x, y + nextSize, nextSize);
            solve(x + nextSize, y, nextSize);
            solve(x + nextSize, y + nextSize, nextSize);
        } else {
            num += (size * size);
        }
    }
}