import java.util.Arrays;
import java.util.Scanner;

/**
 * @author 지종권
 * @date 2024. 1. 30.
 * @link https://www.acmicpc.net/problem/6443
 * @keyword_solution
 * @input
 * @output
 * @time_complex
 * @perf
 */
public class Main {
	static int[] alphabets;
    static StringBuilder sb;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		for (int i = 0; i < n; i++) {
			sb = new StringBuilder();
			alphabets = new int[26];
			String word = sc.next();
			
			for(int j = 0 ; j < word.length(); j++) {
				alphabets[word.charAt(j) - 'a']++;
			}
			
			req(word.length());
		}
	}

	static void req(int depth) {
		// base
		if(depth == sb.length()) {
			System.out.println(sb.toString());
			return;
		}
		
		// inductive
		for(int i = 0; i < 26; i++) {
			if(alphabets[i] > 0) {
				sb.append((char)(i + 'a'));
				alphabets[i]--;
				req(depth);
				alphabets[i]++;
				sb.setLength(sb.length() - 1);
			}
		}

	}
}
