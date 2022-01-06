import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;
import java.util.StringTokenizer;

class point {
    int x;
    int y;
    int cnt;
    int breaked;

    public point(int x, int y, int cnt, int breaked) {
        this.x = x;
        this.y = y;
        this.cnt = cnt;
        this.breaked = breaked;
    }
}

public class Main {

    static int n, m, k;
    static int[][] arr;
    static boolean[][][] visited;

    public static void bfs() {
        Queue<point> queue = new LinkedList<>();
        queue.offer(new point(0, 0, 1, 0));
        for (int i = 0; i <= k; i++) {
            visited[0][0][i] = true;
        }
        int[] dx = { 1, 0, -1, 0 };
        int[] dy = { 0, 1, 0, -1 };
        while (!queue.isEmpty()) {
            point p = queue.poll();
            if (p.x == n - 1 && p.y == m - 1) {
                System.out.println(p.cnt);
                System.exit(0);
            }
            for (int i = 0; i < 4; i++) {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if (arr[nx][ny] == 1) {
                        if (p.breaked < k && !visited[nx][ny][p.breaked + 1]) {
                            visited[nx][ny][p.breaked + 1] = true;
                            queue.offer(new point(nx, ny, p.cnt + 1, p.breaked + 1));
                        }
                    } else if (arr[nx][ny] == 0) {
                        if (!visited[nx][ny][p.breaked]) {
                            visited[nx][ny][p.breaked] = true;
                            queue.offer(new point(nx, ny, p.cnt + 1, p.breaked));
                        }
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        arr = new int[n][m];
        visited = new boolean[n][m][k + 1];
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = str.charAt(j) - '0';
            }
        }
        bfs();
        System.out.println(-1);
    }
}