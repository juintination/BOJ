import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		while (true) {
			int[] n = new int[3];
			int max = 0, sum = 0;
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			for (int i = 0; i < 3; i++) {
				n[i] = Integer.parseInt(st.nextToken());
			}
			if (n[0] == 0 && n[1] == 0 && n[2] == 0) break;
			for (int i = 0; i < 3; i++) {
				max = Math.max(max, n[i]);
			}
			for (int i = 0; i < 3; i++) {
				if (n[i] != max) {
					sum += n[i] * n[i];
				}
			}
			if (sum == max * max) {
				sb.append("right\n");
			} else {
				sb.append("wrong\n");
			}
		}
		System.out.print(sb);
	}
}