import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int min = Integer.MAX_VALUE;
	static boolean[] visited;
	static int[][] arr;

	public static boolean square(int magic) {
		for (int i = 0; i < 3; i++) {
			int horizontal = 0, vertical = 0;
			for (int j = 0; j < 3; j++) {
				horizontal += arr[i][j];
				vertical += arr[j][i];
			}
			if (horizontal != magic || vertical != magic) {
				return false;
			}
		}
		return true;
	}

	public static void dfs(int dpth, int idx, int sum) {
		if (idx == 3) {
			dfs(dpth + 1, 0, sum);
			return;
		}
		if (dpth == 3) {
			int diagonal = arr[0][0] + arr[1][1] + arr[2][2];
			if (diagonal == arr[2][0] + arr[1][1] + arr[0][2]) {
				if (square(diagonal)) {
					min = Math.min(min, sum);
				}
			}
			return;
		}
		int tmp = arr[dpth][idx];
		for (int i = 1; i <= 9; i++) {
			if (!visited[i]) {
				visited[i] = true;
				arr[dpth][idx] = i;
				dfs(dpth, idx + 1, sum + Math.abs(tmp - i));
				arr[dpth][idx] = tmp;
				visited[i] = false;
			}
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		visited = new boolean[10];
		arr = new int[3][3];
		for (int i = 0; i < 3; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < 3; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		dfs(0, 0, 0);
		System.out.println(min);
	}
}