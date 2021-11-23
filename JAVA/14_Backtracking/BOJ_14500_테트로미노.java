import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, m, max;
    static int[][] tetromino;
    static boolean[][] visited;

    public static void dfs(int x, int y, int dpth, int sum) {
        if (dpth == 4) {
            max = Math.max(max, sum);
            return;
        }
        int[] dx = { -1, 0, 1, 0 };
        int[] dy = { 0, -1, 0, 1 };
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                visited[nx][ny] = true;
                dfs(nx, ny, dpth + 1, sum + tetromino[nx][ny]);
                visited[nx][ny] = false;
            }
        }
    }

    public static void mountain(int x, int y) {
        int wing = 4, min = 1001;
        int sum = tetromino[x][y];
        int[] dx = { -1, 0, 1, 0 };
        int[] dy = { 0, -1, 0, 1 };
        for (int i = 0; i < 4; i++) {
            if (wing <= 2) {
                return;
            }
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                min = Math.min(min, tetromino[nx][ny]);
                sum += tetromino[nx][ny];
            } else {
                wing--;
            }
        }
        if (wing == 4) {
            sum -= min;
        }
        max = Math.max(max, sum);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        tetromino = new int[m][n];
        visited = new boolean[m][n];
        for (int j = 0; j < n; j++) {
            st = new StringTokenizer(br.readLine(), " ");
            for (int i = 0; i < m; i++) {
                tetromino[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        max = 0;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                dfs(i, j, 0, 0);
                mountain(i, j);
            }
        }
        System.out.println(max);
    }
}