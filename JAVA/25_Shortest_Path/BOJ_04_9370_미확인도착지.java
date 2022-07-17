import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Collections;
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

    final static int INF = Integer.MAX_VALUE / 3;
    static int[] min;
    static boolean[] visited;
    static ArrayList<point>[] list;

    public static int dijkstra(int from, int to) {
        PriorityQueue<point> queue = new PriorityQueue<>();
        queue.offer(new point(from, 0));
        Arrays.fill(visited, false);
        Arrays.fill(min, INF);
        min[from] = 0;
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
        return min[to];
    }

    @SuppressWarnings("unchecked")
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int t = Integer.parseInt(st.nextToken());
            min = new int[n + 1];
            visited = new boolean[n + 1];
            list = new ArrayList[n + 1];
            for (int i = 1; i <= n; i++) {
                list[i] = new ArrayList<point>();
            }
            st = new StringTokenizer(br.readLine(), " ");
            int s = Integer.parseInt(st.nextToken());
            int g = Integer.parseInt(st.nextToken());
            int h = Integer.parseInt(st.nextToken());
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine(), " ");
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                int d = Integer.parseInt(st.nextToken());
                list[a].add(new point(b, d));
                list[b].add(new point(a, d));
            }
            ArrayList<Integer> candidate = new ArrayList<>();
            for (int i = 0; i < t; i++) {
                int x = Integer.parseInt(br.readLine());
                int sghx = dijkstra(s, g) + dijkstra(g, h) + dijkstra(h, x);
                int shgx = dijkstra(s, h) + dijkstra(h, g) + dijkstra(g, x);
                if (Math.min(sghx, shgx) == dijkstra(s, x)) {
                    candidate.add(x);
                }
            }
            Collections.sort(candidate);
            for (int x : candidate) {
                sb.append(x).append(" ");
            }
            sb.append("\n");
        }
        System.out.print(sb);
    }
}