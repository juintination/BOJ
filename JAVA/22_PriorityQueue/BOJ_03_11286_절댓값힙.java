import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

class point implements Comparable<point> {
	int x, abs;

	public point(int x) {
		this.x = x;
		this.abs = Math.abs(x);
	}

	@Override
	public int compareTo(point o) {
		if (this.abs == o.abs) {
			return this.x - o.x;
		} else {
			return this.abs - o.abs;
		}
	}
}

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PriorityQueue<point> pqueue = new PriorityQueue<>();
		int n = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		while (n-- > 0) {
			int x = Integer.parseInt(br.readLine());
			if (x == 0) {
				if (!pqueue.isEmpty()) {
					sb.append(pqueue.poll().x).append("\n");
				} else {
					sb.append(0).append("\n");
				}
			} else {
				pqueue.offer(new point(x));
			}
		}
		System.out.print(sb);
	}
}