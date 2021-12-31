import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int n;
	static int[] arr;
	static boolean[] visited;

	public static void dfs(int dpth, int sum) {
		if (dpth == n) {
			visited[sum] = true;
			return;
		}
		dfs(dpth + 1, sum);
		dfs(dpth + 1, sum + arr[dpth]);
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		arr = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		visited = new boolean[2000001];
		dfs(0, 0);
		int result = 1;
		while (true) {
			if (!visited[result++]) {
				System.out.println(result - 1);
				break;
			}
		}
	}
}