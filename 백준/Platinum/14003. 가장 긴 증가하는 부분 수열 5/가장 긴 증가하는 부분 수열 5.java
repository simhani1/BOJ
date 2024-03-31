import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N;
    private static int[] arr;
    private static int[] lis;
    private static int[] index;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        arr = new int[N + 1];
        lis = new int[N + 1];
        index = new int[N + 1];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        lis[0] = arr[0];
        index[0] = 0;
        int len = 1;
        for (int i = 1; i < N; i++) {
            if (lis[len - 1] < arr[i]) {
                lis[len] = arr[i];
                index[i] = len;
                len++;
            } else {
                int idx = binarySearch(0, len - 1, arr[i]);
                lis[idx] = arr[i];
                index[i] = idx;
            }
        }
        sb.append(len).append("\n");
        List<Integer> list = new ArrayList<>();
        for (int i = N - 1; i >= 0; i--) {
            if (index[i] == len - 1) {
                list.add(arr[i]);
                len--;
            }
        }
        for (int i = list.size() - 1; i >= 0; i--) {
            sb.append(list.get(i)).append(" ");
        }
        System.out.println(sb.toString());
    }

    private static int binarySearch(int l, int r, int target) {
        while (l <= r) {
            int mid = (l + r) / 2;
            if (lis[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
}