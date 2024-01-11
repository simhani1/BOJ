import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        int[][] arr = new int[51][51];
        boolean[][] isFriend = new boolean[51][51];
        String str = br.readLine();
        int N = Integer.parseInt(str);
        for (int i = 0; i < N; i++) {
            String info = br.readLine();
            for (int j = 0; j < N; j++) {
                if(info.charAt(j) == 'Y')
                    arr[i][j] = 1;
                else
                    arr[i][j] = 0;
            }
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] == 1) {
                    isFriend[i][j] = true;
                    for (int k = 0; k < N; k++) {
                        if (arr[j][k] == 1) {
                            isFriend[i][k] = true;
                        }
                    }
                }
            }
            int cnt = 0;
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    continue;
                }
                if (isFriend[i][j]) {
                    cnt++;
                }
            }
            ans = Math.max(ans, cnt);
        }
        System.out.println(ans);
    }
}