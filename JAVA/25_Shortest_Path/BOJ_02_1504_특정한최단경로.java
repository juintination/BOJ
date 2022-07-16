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
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());
        min = new int[n + 1];
        visited = new boolean[n + 1];
        list = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            list[i] = new ArrayList<point>();
        }
        for (int i = 0; i < e; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            list[a].add(new point(b, c));
            list[b].add(new point(a, c));
        }
        st = new StringTokenizer(br.readLine(), " ");
        int v1 = Integer.parseInt(st.nextToken());
        int v2 = Integer.parseInt(st.nextToken());
        int route1 = 0, route2 = 0;
        route1 += dijkstra(1, v1);
        route1 += dijkstra(v1, v2);
        route1 += dijkstra(v2, n);
        route2 += dijkstra(1, v2);
        route2 += dijkstra(v2, v1);
        route2 += dijkstra(v1, n);
        int route = Math.min(route1, route2);
        System.out.println(route >= INF ? -1 : route);
    }
}