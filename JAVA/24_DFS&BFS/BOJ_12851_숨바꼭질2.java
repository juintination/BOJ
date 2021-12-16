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

    static int n, k, cnt = 0;
    static int min = Integer.MAX_VALUE;
    static boolean[] visited = new boolean[100001];
    static StringBuilder sb = new StringBuilder();

    public static void bfs() {
        PriorityQueue<point> queue = new PriorityQueue<point>();
        queue.offer(new point(n, 0));
        while (!queue.isEmpty()) {
            point p = queue.poll();
            visited[p.x] = true;
            if (p.x == k && min >= p.cnt) {
                min = p.cnt;
                cnt++;
            }
            int[] dx = { p.x - 1, p.x + 1, p.x * 2 };
            for (int nx : dx) {
                if (nx >= 0 && nx <= 100000 && !visited[nx]) {
                    queue.offer(new point(nx, p.cnt + 1));
                }
            }
        }
        sb.append(min).append("\n").append(cnt);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        bfs();
        System.out.println(sb);
    }
}