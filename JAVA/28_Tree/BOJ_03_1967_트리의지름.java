import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

class node {
	int data;
	int cost;

	public node(int data, int cost) {
		this.data = data;
		this.cost = cost;
	}
}

public class Main {

	static int n, tmp, max = 0;
	static boolean[] visited;
	static ArrayList<node>[] list;

	public static void dfs(int idx, int len) {
		if (len > max) {
			max = len;
			tmp = idx;
		}
		visited[idx] = true;
		if (list[idx] != null) {
			for (node n : list[idx]) {
				if (!visited[n.data]) {
					dfs(n.data, len + n.cost);
					visited[n.data] = false;
				}
			}
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		list = new ArrayList[n + 1];
		visited = new boolean[n + 1];
		for (int i = 1; i <= n; i++) {
			list[i] = new ArrayList<>();
		}
		for (int i = 0; i < n - 1; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			int idx = Integer.parseInt(st.nextToken());
			int data = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());
			list[idx].add(new node(data, cost));
			list[data].add(new node(idx, cost));
		}
		dfs(1, 0);
		Arrays.fill(visited, false);
		dfs(tmp, 0);
		System.out.println(max);
	}
}