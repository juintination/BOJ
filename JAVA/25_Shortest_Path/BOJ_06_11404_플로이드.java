import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    final static int INF = Integer.MAX_VALUE / 2;
    static StringBuilder sb = new StringBuilder();

    public static void floydWarshall(int[][] route, int n) {
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    route[i][j] = Math.min(route[i][j], route[i][k] + route[k][j]);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                sb.append(route[i][j] != INF ? route[i][j] : 0).append(" ");
            }
            sb.append("\n");
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        int[][] route = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            Arrays.fill(route[i], INF);
            route[i][i] = 0;
        }
        while (m-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            route[a][b] = Math.min(route[a][b], c);
        }
        floydWarshall(route, n);
        System.out.print(sb);
    }
}