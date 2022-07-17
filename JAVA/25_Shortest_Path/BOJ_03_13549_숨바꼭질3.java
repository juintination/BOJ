import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class point implements Comparable<point> {
    int x;
    int cnt;

    public point(int x, int cnt) {
        this.x = x;
        this.cnt = cnt;
    }

    @Override
    public int compareTo(point o) {
        return this.cnt - o.cnt;
    }
}

public class Main {

    static int n, k, result;
    static boolean[] visited = new boolean[100001];

    public static void bfs(int idx) {
        PriorityQueue<point> queue = new PriorityQueue<>();
        queue.offer(new point(idx, 0));
        while (!queue.isEmpty()) {
            point p = queue.poll();
            visited[p.x] = true;
            if (p.x == k) {
                result = p.cnt;
                return;
            }
            int[] dx = { p.x - 1, p.x + 1, p.x * 2 };
            for (int nx : dx) {
                if (nx >= 0 && nx <= 100000 && !visited[nx]) {
                    if (nx == p.x * 2) {
                        queue.offer(new point(nx, p.cnt));
                    } else {
                        queue.offer(new point(nx, p.cnt + 1));
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        bfs(n);
        System.out.println(result);
    }
}