import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N;
	static List<String> list = new ArrayList<>();

	public static void main(String[] args) throws IOException {
		N = Integer.parseInt(br.readLine());
		for (int i = 0; i < N; i++) {
			list.add(br.readLine());
		}
		int maxCnt = 0;
		int sIdx = 0, rIdx = 0;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				int cnt = 0;
				for (int k = 0; k < Math.min(list.get(i).length(), list.get(j).length()); k++) {
					if (list.get(i).charAt(k) == list.get(j).charAt(k)) {
						cnt++;
					} else {
						break;
					}
				}
				if (cnt > maxCnt) {
					maxCnt = cnt;
					sIdx = i;
					rIdx = j;
				}
			}
		}
		sb.append(list.get(sIdx)).append("\n").append(list.get(rIdx));
		System.out.println(sb);
	}

}