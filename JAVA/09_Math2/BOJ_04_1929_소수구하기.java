import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int m = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());
		boolean[] tst = new boolean[n + 1];
		tst[1] = true;
		StringBuilder sb = new StringBuilder();
		for (int i = 2; i <= (int) Math.sqrt(n); i++) {
			if (tst[i]) continue;
			for (int j = i * i; j <= n; j += i) {
				tst[j] = true;
			}
		}
		for (int i = m; i <= n; i++) {
			if (!tst[i]) sb.append(i).append("\n");
		}
		System.out.print(sb);
	}
}