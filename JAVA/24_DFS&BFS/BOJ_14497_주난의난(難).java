import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class point implements Comparable<point> {
    int x, y, cnt;

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

    static int n, m, x1, y1, x2, y2;
    static char[][] arr;
    static boolean[][] visited;

    public static void bfs() {
        PriorityQueue<point> queue = new PriorityQueue<>();
        queue.offer(new point(x1 - 1, y1 - 1, 1));
        visited[x1 - 1][y1 - 1] = true;
        int[] dx = { -1, 0, 1, 0 };
        int[] dy = { 0, -1, 0, 1 };
        while (!queue.isEmpty()) {
            point p = queue.poll();
            for (int i = 0; i < 4; i++) {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    if (arr[nx][ny] == '0') {
                        queue.offer(new point(nx, ny, p.cnt));
                    } else if (arr[nx][ny] == '1') {
                        queue.offer(new point(nx, ny, p.cnt + 1));
                    } else {
                        System.out.println(p.cnt);
                        System.exit(0);
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
        arr = new char[n][m];
        visited = new boolean[n][m];
        st = new StringTokenizer(br.readLine(), " ");
        x1 = Integer.parseInt(st.nextToken());
        y1 = Integer.parseInt(st.nextToken());
        x2 = Integer.parseInt(st.nextToken());
        y2 = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = str.charAt(j);
            }
        }
        bfs();
    }
}