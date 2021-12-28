import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

	static int[] parent;
	static boolean[] visited;
	static ArrayList<Integer>[] list;

	public static void dfs(int idx) {
		if (visited[idx]) {
			return;
		}
		visited[idx] = true;
		for (int e : list[idx]) {
			if(!visited[e]) {
				parent[e] = idx;
				dfs(e);
			}
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		parent = new int[n + 1];
		visited = new boolean[n + 1];
		list = new ArrayList[n + 1];
		for (int i = 1; i <= n; i++) {
			list[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < n - 1; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			list[x].add(y);
			list[y].add(x);
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				dfs(i);
			}
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 2; i <= n; i++) {
			sb.append(parent[i]).append("\n");
		}
		System.out.print(sb);
	}
}