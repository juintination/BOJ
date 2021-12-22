import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

    static int n, min;
    static int[][] arr, num;
    static boolean[][] visited;

    public static void dfs(int x, int y, int cnt) {
        visited[x][y] = true;
        num[x][y] = cnt;
        int[] dx = { -1, 0, 1, 0 };
        int[] dy = { 0, -1, 0, 1 };
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && arr[nx][ny] == 1) {
                dfs(nx, ny, cnt);
            }
        }
    }

    public static void bfs(int x, int y) {
        Queue<int[]> queue = new LinkedList<int[]>();
        queue.offer(new int[] { x, y });
        visited = new boolean[n][n];
        visited[x][y] = true;
        int idx = num[x][y];
        int[] dx = { -1, 0, 1, 0 };
        int[] dy = { 0, -1, 0, 1 };
        while (!queue.isEmpty()) {
            x = queue.peek()[0];
            y = queue.poll()[1];
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && num[nx][ny] != idx) {
                    visited[nx][ny] = true;
                    if (num[nx][ny] == 0) {
                        arr[nx][ny] = arr[x][y] + 1;
                        queue.offer(new int[] { nx, ny });
                    } else {
                        min = Math.min(min, arr[x][y] - 1);
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n][n];
        num = new int[n][n];
        visited = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int cnt = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && arr[i][j] == 1) {
                    dfs(i, j, cnt++);
                }
            }
        }
        min = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (num[i][j] > 0) {
                    bfs(i, j);
                }
            }
        }
        System.out.println(min);
    }
}