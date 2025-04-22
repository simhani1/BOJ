import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int N;
    static String[] arr;
    static long[][] info;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        arr = new String[N];
        info = new long[10][2];
        visited = new boolean[10];
        for (int i = 0; i < N; i++) {
            arr[i] = br.readLine();
            info[arr[i].charAt(0) - 'A'][0] = 1;
            for (int j = 0; j < arr[i].length(); j++) {
                int idx = arr[i].charAt(j) - 'A';
                info[idx][1] += Math.pow(10, arr[i].length() - 1 - j);
            }
        }
        Arrays.sort(info, (o1, o2) -> Long.compare(o1[1], o2[1]));
        long ans = 0;
        for (int i = 0; i < 10; i++) {
            long ten = info[i][1];
            for (int num = (int)info[i][0]; num < 10; num++) {
                if (!visited[num]) {
                    ans += (ten * (long)num);
                    visited[num] = true;
                    break;
                }
            }
        }
        System.out.println(ans);
    }
}