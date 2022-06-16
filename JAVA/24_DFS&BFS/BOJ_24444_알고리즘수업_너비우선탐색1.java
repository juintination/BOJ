import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

	static int n, m, r, cnt = 1;
	static int[] sequence;
	static boolean[] visited;
	static ArrayList<Integer>[] list;

	public static void bfs(int value) {
		Queue<Integer> queue = new LinkedList<>();
		queue.offer(value);
		visited[value] = true;
		sequence[value] = cnt++;
		while (!queue.isEmpty()) {
			int p = queue.poll();
			for (int e : list[p]) {
				if (!visited[e]) {
					visited[e] = true;
					sequence[e] = cnt++;
					queue.offer(e);
				}
			}
		}
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		visited = new boolean[n + 1];
		list = new ArrayList[n + 1];
		sequence = new int[n + 1];
		Arrays.fill(sequence, 0);
		for (int i = 1; i <= n; i++) {
			list[i] = new ArrayList<Integer>();
		}
		while (m-- > 0) {
			st = new StringTokenizer(br.readLine(), " ");
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			list[x].add(y);
			list[y].add(x);
		}
		for (int i = 1; i <= n; i++) {
			Collections.sort(list[i]);
		}
		bfs(r);
		StringBuilder sb = new StringBuilder();
		for (int i = 1; i <= n; i++) {
			sb.append(sequence[i]).append("\n");
		}
		System.out.print(sb);
	}
}