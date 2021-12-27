import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		boolean[] tst = new boolean[10001];
		tst[1] = true;
		for (int i = 2; i <= 100; i++) {
			if (tst[i]) continue;
			for (int j = i * i; j <= 10000; j += i) {
				tst[j] = true;
			}
		}
		StringBuilder sb = new StringBuilder();
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			int n = Integer.parseInt(br.readLine());
			int i = n / 2;
			int j = n / 2;
			while (true) {
				if (!tst[i] && !tst[j]) {
					sb.append(i).append(" ").append(j).append("\n");
					break;
				}
				i--;
				j++;
			}
		}
		System.out.print(sb);
	}
}