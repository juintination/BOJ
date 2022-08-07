import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class point {
    boolean teleport;
    int r, c;

    public point(boolean teleport, int r, int c) {
        this.teleport = teleport;
        this.r = r;
        this.c = c;
    }
}

public class Main {

    final static int INF = Integer.MAX_VALUE / 2;

    public static void floydWarshall(int[][] route, int n) {
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    route[i][j] = Math.min(route[i][j], route[i][k] + route[k][j]);
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int t = Integer.parseInt(st.nextToken());
        int[][] route = new int[n + 1][n + 1];
        point[] city = new point[n + 1];
        for (int i = 1; i <= n; i++) {
            Arrays.fill(route[i], INF);
            route[i][i] = 0;
            st = new StringTokenizer(br.readLine(), " ");
            int s = Integer.parseInt(st.nextToken());
            boolean teleported = s == 1 ? true : false;
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            city[i] = new point(teleported, x, y);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                if (city[i].teleport && city[j].teleport) {
                    route[i][j] = route[j][i] = Math.min(t, Math.abs(city[i].r - city[j].r) + Math.abs(city[i].c - city[j].c));
                } else {
                    route[i][j] = Math.abs(city[i].r - city[j].r) + Math.abs(city[i].c - city[j].c);
                }
            }
        }
        floydWarshall(route, n);
        int m = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            sb.append(route[a][b]).append("\n");
        }
        System.out.print(sb);
    }
}