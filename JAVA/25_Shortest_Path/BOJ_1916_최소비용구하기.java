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

    static int[] min;
    static ArrayList<point>[] buses;

    public static void dijkstra(int from, int to) {
        PriorityQueue<point> queue = new PriorityQueue<>();
        queue.offer(new point(from, 0));
        while (!queue.isEmpty()) {
            point p = queue.poll();
            if (min[p.x] < p.cost) continue;
            if (buses[p.x] != null) {
                for (point e : buses[p.x]) {
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
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        min = new int[n + 1];
        buses = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            buses[i] = new ArrayList<point>();
        }
        for (int i = 0; i < m; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            buses[u].add(new point(v, w));
        }
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int from = Integer.parseInt(st.nextToken());
        int to = Integer.parseInt(st.nextToken());
        Arrays.fill(min, Integer.MAX_VALUE);
        min[from] = 0;
        dijkstra(from, to);
        System.out.println(min[to]);
    }
}