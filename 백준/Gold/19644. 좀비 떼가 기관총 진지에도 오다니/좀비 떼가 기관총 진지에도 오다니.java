import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int L, ML, MK, C;
    static int[] arr, pSum;

    public static void main(String[] args) throws IOException {
        L = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        ML = Integer.parseInt(st.nextToken());
        MK = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(br.readLine());
        int nowC = C;
        arr = new int[L + 1];
        pSum = new int[L + 1];
        for (int i = 1; i <= L; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        for (int i = 1; i <= L; i++) {
            pSum[i] += pSum[i - 1];
            int damage = Math.min(i * MK, ML * MK) - pSum[i] * MK;
            if (arr[i] > damage) {
                if (nowC > 0) {
                    nowC--;
                    pSum[i]++;
                    if (i + ML <= L) {
                        pSum[i + ML]--;
                    }
                } else {
                    System.out.println("NO");
                    return;
                }
            }
        }
        System.out.println("YES");
    }
}