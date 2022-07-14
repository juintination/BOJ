import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.StringTokenizer;

class point implements Comparable<point> {
    int x, cost;

    public point(int x, int cost) {
        this.x = x;
        this.cost = cost;
    }

    @Override
    public int compareTo(point o) {
        return cost - o.cost;
    }
}

public class Main {

    final static int INF = Integer.MAX_VALUE;

    static int n, m, k;
    static int[] min;
    static boolean[] visited;
    static ArrayList<point>[] list;

    public static void bfs() {
        PriorityQueue<point> queue = new PriorityQueue<>();
        queue.offer(new point(k, 0));
        while (!queue.isEmpty()) {
            point p = queue.poll();
            if (visited[p.x]) continue;
            visited[p.x] = true;
            if (list[p.x] != null) {
                for (point e : list[p.x]) {
                    int cost = e.cost + p.cost;
                    if (min[e.x] > cost) {
                        min[e.x] = cost;
                        queue.offer(new point(e.x, cost));
                    }
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
        min = new int[n + 1];
        visited = new boolean[n + 1];
        list = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            list[i] = new ArrayList<point>();
        }
        k = Integer.parseInt(br.readLine());
        Arrays.fill(min, INF);
        min[k] = 0;
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            list[u].add(new point(v, w));
        }
        bfs();
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= n; i++) {
            if (min[i] == INF) {
                sb.append("INF\n");
            } else {
                sb.append(min[i]).append("\n");
            }
        }
        System.out.print(sb);
    }
}