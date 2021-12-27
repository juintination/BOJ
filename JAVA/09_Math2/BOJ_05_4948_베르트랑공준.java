import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		boolean[] tst = new boolean[246913];
		tst[1] = true;
		for (int i = 2; i <= (int) Math.sqrt(246912); i++) {
			if (tst[i]) continue;
			for (int j = i * i; j <= 246912; j += i) {
				tst[j] = true;
			}
		}
		StringBuilder sb = new StringBuilder();
		while (true) {
			int n = Integer.parseInt(br.readLine());
			if (n == 0) break;
			int cnt = 0;
			for (int i = n + 1; i <= 2 * n; i++) {
				if (!tst[i])
					cnt++;
			}
			sb.append(cnt).append("\n");
		}
		System.out.print(sb);
	}
}