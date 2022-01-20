import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class point implements Comparable<point> {
    int p, d;

    public point(int p, int d) {
        this.p = p;
        this.d = d;
    }

    @Override
    public int compareTo(point o) {
        return o.p - p;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        PriorityQueue<point> queue = new PriorityQueue<>();
        int max = 0;
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int p = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            queue.offer(new point(p, d));
            max = Math.max(max, d);
        }
        boolean[] visited = new boolean[max + 1];
        int sum = 0;
        while (!queue.isEmpty()) {
            point p = queue.poll();
            while (p.d-- > 0) {
                if (!visited[p.d]) {
                    visited[p.d] = true;
                    sum += p.p;
                    break;
                }
            }
        }
        System.out.println(sum);
    }
}