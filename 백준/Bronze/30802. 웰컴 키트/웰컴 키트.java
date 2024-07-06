import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N, T, P;
    private static int[] arr;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        arr = new int[6];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 6; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        T = Integer.parseInt(st.nextToken());
        P = Integer.parseInt(st.nextToken());
        int penBundle = N / P;
        int pen = N % P;
        int shirt = 0;
        for (int i = 0; i < 6; i++) {
            shirt += (arr[i] / T);
            if (arr[i] % T != 0) {
                shirt++;
            }
        }
        System.out.println(sb.append(shirt).append("\n").append(penBundle).append(" ").append(pen));
    }

}