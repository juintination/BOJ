import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, m, cnt = 0;
    static boolean[][] com;
    static boolean[] visited;

    public static void dfs(int dpth) {
        visited[dpth] = true;
        for (int i = 1; i <= n; i++) {
            if (com[dpth][i] && !visited[i]) {
                cnt++;
                dfs(i);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());
        com = new boolean[n + 1][n + 1];
        visited = new boolean[n + 1];
        while (m-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            com[x][y] = true;
            com[y][x] = true;
        }
        dfs(1);
        System.out.println(cnt);
    }
}