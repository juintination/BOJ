import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n;
    static boolean tst = false;
    static int[][] jelly;
    static boolean[][] visited;

    public static void dfs(int x, int y) {
        if (x == n - 1 && y == n - 1) {
            tst = true;
            return;
        }
        int[] dx = { 1, 0 };
        int[] dy = { 0, 1 };
        visited[x][y] = true;
        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i] * jelly[x][y];
            int ny = y + dy[i] * jelly[x][y];
            if (nx < n && ny < n && !visited[nx][ny]) {
                dfs(nx, ny);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        jelly = new int[n][n];
        visited = new boolean[n][n];
        for (int j = 0; j < n; j++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            for (int i = 0; i < n; i++) {
                jelly[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        dfs(0, 0);
        if (tst) {
            System.out.println("HaruHaru");
        } else {
            System.out.println("Hing");
        }
    }
}