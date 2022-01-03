import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int n, m, max = 1;
	static char[][] arr;
	static boolean[] alph;

	public static void dfs(int x, int y, int dpth) {
		alph[arr[x][y] - 'A'] = true;
		int[] dx = { -1, 0, 1, 0 };
		int[] dy = { 0, -1, 0, 1 };
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !alph[arr[nx][ny] - 'A']) {
				max = Math.max(max, dpth + 1);
				dfs(nx, ny, dpth + 1);
				alph[arr[nx][ny] - 'A'] = false;
			}
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new char[n][m];
		alph = new boolean[26];
		for (int i = 0; i < n; i++) {
			String str = br.readLine();
			for (int j = 0; j < m; j++) {
				arr[i][j] = str.charAt(j);
			}
		}
		dfs(0, 0, 1);
		System.out.println(max);
	}
}