import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		while (t-- > 0) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			int x1 = Integer.parseInt(st.nextToken());
			int y1 = Integer.parseInt(st.nextToken());
			int r1 = Integer.parseInt(st.nextToken());
			int x2 = Integer.parseInt(st.nextToken());
			int y2 = Integer.parseInt(st.nextToken());
			int r2 = Integer.parseInt(st.nextToken());
			double d = Math.sqrt(Math.pow(x1 - x2, 2) + Math.pow(y1 - y2, 2));
			if (d == 0) {
				if (r1 == r2) {
					sb.append(-1).append("\n");
				} else {
					sb.append(0).append("\n");
				}
			} else if (d == r1 + r2 || d == Math.abs(r1 - r2)) {
				sb.append(1).append("\n");
			} else if (d < r1 + r2 && d > Math.abs(r1 - r2)) {
				sb.append(2).append("\n");
			} else {
				sb.append(0).append("\n");
			}
		}
		System.out.print(sb);
	}
}