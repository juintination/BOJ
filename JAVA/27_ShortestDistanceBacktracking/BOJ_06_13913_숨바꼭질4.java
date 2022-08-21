import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	static int[] dp = new int[100001], parent = new int[100001];

	public static void bfs(int n, int k) {
		Queue<Integer> queue = new LinkedList<>();
		queue.offer(n);
		while (!queue.isEmpty()) {
			int x = queue.poll();
			if (x == k)
				break;
			int[] dx = { x - 1, x + 1, x * 2 };
			for (int nx : dx) {
				if (0 <= nx && nx <= 100000 && dp[nx] == 0) {
					queue.offer(nx);
					dp[nx] = dp[x] + 1;
					parent[nx] = x;
				}
			}
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		bfs(n, k);
		StringBuilder sb = new StringBuilder();
		sb.append(dp[k]).append("\n");
		Stack<Integer> stack = new Stack<>();
		int tmp = k;
		while (tmp != n) {
			stack.push(tmp);
			tmp = parent[tmp];
		}
		stack.push(tmp);
		while (!stack.isEmpty()) {
			sb.append(stack.pop()).append(" ");
		}
		System.out.println(sb);
	}
}