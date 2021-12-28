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

	static int v, tmp, max = 0;
	static boolean[] visited;
	static ArrayList<node>[] list;

	public static void dfs(int idx, int len) {
		if (len > max) {
			max = len;
			tmp = idx;
		}
		visited[idx] = true;
		for (node n : list[idx]) {
			if (!visited[n.data]) {
				dfs(n.data, len + n.cost);
				visited[n.data] = false;
			}
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		v = Integer.parseInt(br.readLine());
		list = new ArrayList[v + 1];
		visited = new boolean[v + 1];
		for (int i = 1; i <= v; i++) {
			list[i] = new ArrayList<>();
		}
		for (int i = 0; i < v; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			int n = Integer.parseInt(st.nextToken());
			while (true) {
				int data = Integer.parseInt(st.nextToken());
				if (data == -1) break;
				int cost = Integer.parseInt(st.nextToken());
				list[n].add(new node(data, cost));
			}
		}
		dfs(1, 0);
		Arrays.fill(visited, false);
		dfs(tmp, 0);
		System.out.println(max);
	}
}