import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

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
        int min = INF, idx = 0;
        for (int i = 1; i <= n; i++) {
            int kevinBacon = 0;
            for (int j = 1; j <= n; j++) {
                kevinBacon += route[i][j] != INF ? route[i][j] : 0;
            }
            if (kevinBacon < min) {
                min = kevinBacon;
                idx = i;
            }
        }
        System.out.println(idx);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] route = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            Arrays.fill(route[i], INF);
            route[i][i] = 0;
        }
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            route[a][b] = route[b][a] = 1;
        }
        floydWarshall(route, n);
    }
}