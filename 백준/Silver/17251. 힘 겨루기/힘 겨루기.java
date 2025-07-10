import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N, redCnt, blueCnt;
	static int[] arr, red, blue;

	public static void main(String[] args) throws IOException {
		N = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		arr = new int[N + 2];
		red = new int[N + 2];
		blue = new int[N + 2];
		for (int i = 1; i <= N; i++) arr[i] = Integer.parseInt(st.nextToken());
		for (int i = 1; i <= N; i++) red[i] = Math.max(red[i - 1], arr[i]);
		for (int i = N; i >= 1; i--) blue[i] = Math.max(blue[i + 1], arr[i]);
		redCnt = blueCnt = 0;
		for (int i = 1; i < N; i++) {
			if (red[i] > blue[i + 1]) redCnt++;
			else if (red[i] < blue[i + 1]) blueCnt++;
		}
		if (redCnt == blueCnt) System.out.println("X");
		else if (redCnt > blueCnt) System.out.println("R");
		else System.out.println("B");
	}
}