import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[] cnt_x = new int[1001];
		int[] cnt_y = new int[1001];
		int max = 0;
		for (int i = 0; i < 3; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			cnt_x[x]++;
			cnt_y[y]++;
			int z = Math.max(x, y);
			max = Math.max(max, z);
		}
		int[] result = new int[2];
		for (int i = 1; i <= max; i++) {
			if (cnt_x[i] == 1) {
				result[0] = i;
			}
			if (cnt_y[i] == 1) {
				result[1] = i;
			}
		}
		System.out.println(result[0] + " " + result[1]);
	}
}