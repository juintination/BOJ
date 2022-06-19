import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PriorityQueue<Integer> pqueue = new PriorityQueue<>();
		int n = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		while (n-- > 0) {
			int x = Integer.parseInt(br.readLine());
			if (x == 0) {
				if (!pqueue.isEmpty()) {
					sb.append(pqueue.poll()).append("\n");
				} else {
					sb.append(0).append("\n");
				}
			} else {
				pqueue.offer(x);
			}
		}
		System.out.print(sb);
	}
}