import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;

class point {
    int x, y;

    public point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {

    static int n, cnt;
    static char[][] arr;
    static boolean[][] visited;

    public static void dfs(int x, int y) {
        visited[x][y] = true;
        int[] dx = { -1, 0, 1, 0 };
        int[] dy = { 0, -1, 0, 1 };
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                if (arr[nx][ny] == arr[x][y] || Math.abs(arr[nx][ny] - arr[x][y]) == 11) {
                    dfs(nx, ny);
                }
            }
        }
    }

    public static void bfs(int x, int y) {
        Queue<point> queue = new LinkedList<>();
        queue.offer(new point(x, y));
        visited[x][y] = true;
        int[] dx = { -1, 0, 1, 0 };
        int[] dy = { 0, -1, 0, 1 };
        while (!queue.isEmpty()) {
            point p = queue.poll();
            for (int i = 0; i < 4; i++) {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && arr[nx][ny] == arr[p.x][p.y]) {
                    visited[nx][ny] = true;
                    queue.offer(new point(nx, ny));
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new char[n][n];
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < n; j++) {
                arr[i][j] = str.charAt(j);
            }
        }
        cnt = 0;
        visited = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        sb.append(cnt).append(" ");
        cnt = 0;
        visited = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        sb.append(cnt);
        System.out.println(sb);
    }
}