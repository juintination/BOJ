import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.StringTokenizer;

class point {
    int from, to, cost;

    public point(int from, int to, int cost) {
        this.from = from;
        this.to = to;
        this.cost = cost;
    }
}

public class Main {

    final static int INF = Integer.MAX_VALUE;
    static int n, m;
    static long[] min;
    static ArrayList<point> list;

    public static boolean bellmanFord() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m; j++) {
                point bus = list.get(j);
                if (min[bus.from] == INF) continue;
                min[bus.to] = Math.min(min[bus.to], min[bus.from] + bus.cost);
            }
        }
        for (int j = 0; j < m; j++) {
            point bus = list.get(j);
            if (min[bus.from] != INF && min[bus.to] > min[bus.from] + bus.cost) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        list = new ArrayList<>();
        min = new long[n + 1];
        Arrays.fill(min, INF);
        min[1] = 0;
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            list.add(new point(a, b, c));
        }
        if (bellmanFord()) {
            System.out.println(-1);
        } else {
            StringBuilder sb = new StringBuilder();
            for (int i = 2; i <= n; i++) {
                sb.append(min[i] != INF ? min[i] : -1).append("\n");
            }
            System.out.print(sb);
        }
    }
}