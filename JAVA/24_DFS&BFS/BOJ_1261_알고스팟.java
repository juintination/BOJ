import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class point implements Comparable<point> {
    int x;
    int y;
    int cnt;

    public point(int x, int y, int cnt) {
        this.x = x;
        this.y = y;
        this.cnt = cnt;
    }

    @Override
    public int compareTo(point o) {
        return this.cnt - o.cnt;
    }
}

public class Main {

    static int n, m, result;
    static int[][] arr;
    static boolean[][] visited;

    public static void bfs() {
        PriorityQueue<point> queue = new PriorityQueue<>();
        queue.offer(new point(0, 0, 0));
        visited[0][0] = true;
        int[] dx = { -1, 0, 1, 0 };
        int[] dy = { 0, -1, 0, 1 };
        while (!queue.isEmpty()) {
            point p = queue.poll();
            if (p.x == n - 1 && p.y == m - 1) {
                result = p.cnt;
                return;
            }
            for (int i = 0; i < 4; i++) {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    if (arr[nx][ny] == 1) {
                        queue.offer(new point(nx, ny, p.cnt + 1));
                    } else if (arr[nx][ny] == 0) {
                        queue.offer(new point(nx, ny, p.cnt));
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        arr = new int[n][m];
        visited = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = str.charAt(j) - '0';
            }
        }
        bfs();
        System.out.println(result);
    }
}