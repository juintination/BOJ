import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int m = Integer.parseInt(br.readLine());
		int n = Integer.parseInt(br.readLine());
		int sum = 0, min = 0;
		boolean tst = false;
		for (int i = m; i <= n; i++) {
			int cnt = 0;
			for (int j = 0; j < i; j++) {
				if (i % (j + 1) == 0) {
					cnt++;
				}
			}
			if (cnt == 2) {
				sum += i;
				if (tst == false) {
					min = i;
				}
				tst = true;
			}
		}
		if (sum != 0) {
			System.out.println(sum + "\n" + min);
		} else {
			System.out.println(-1);
		}
	}
}