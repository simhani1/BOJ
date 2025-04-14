import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int A, K, cnt = 0;
    private static int[] arr;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        A = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        arr = new int[A];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < A; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        quickSort(0, A - 1);
        System.out.println(-1);
    }

    private static void quickSort(int start, int end) {
        if (start < end) {
            int pivotIdx = partition(start, end);
            quickSort(start, pivotIdx - 1);
            quickSort(pivotIdx + 1, end);
        }
    }

    private static int partition(int start, int end) {
        int pivot = arr[end];
        int i = start - 1;
        for (int j = start; j < end; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(i, j);
                if (++cnt == K) {
                    System.out.println(arr[i] + " " + arr[j]);
                    System.exit(0);
                }
            }
        }
        if (i + 1 != end) {
            swap(i + 1, end);  // pivot이 들어가야 하는 자리 == i + 1
            if (++cnt == K) {
                System.out.println(arr[i + 1] + " " + arr[end]);
                System.exit(0);
            }   
        }
        return i + 1;
    }

    private static void swap(int a, int b) {
        int tmp = arr[b];
        arr[b] = arr[a];
        arr[a] = tmp;
    }
}