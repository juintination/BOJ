import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.LinkedList;

class point {
    int x1, y1, x2, y2, cnt;

    public point(int x1, int y1, int x2, int y2, int cnt) {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
        this.cnt = cnt;
    }
}

public class Main {

    static int n, m, x1, y1, x2, y2;
    static char[][] arr;
    static boolean[][][][] visited;

    public static void bfs() {
        Queue<point> queue = new LinkedList<>();
        queue.offer(new point(x1, y1, x2, y2, 0));
        visited[x1][y1][x2][y2] = true;
        int[] dx = { -1, 0, 1, 0 };
        int[] dy = { 0, -1, 0, 1 };
        while (!queue.isEmpty()) {
            point p = queue.poll();
            if (p.cnt >= 10) break;
            for (int i = 0; i < 4; i++) {
                int nx1 = p.x1 + dx[i];
                int ny1 = p.y1 + dy[i];
                int nx2 = p.x2 + dx[i];
                int ny2 = p.y2 + dy[i];
                int coin = 0;
                if (nx1 >= 0 && nx1 < n && ny1 >= 0 && ny1 < m) {
                    if (arr[nx1][ny1] == '#') {
                        nx1 = p.x1;
                        ny1 = p.y1;
                    }
                    coin++;
                }
                if (nx2 >= 0 && nx2 < n && ny2 >= 0 && ny2 < m) {
                    if (arr[nx2][ny2] == '#') {
                        nx2 = p.x2;
                        ny2 = p.y2;
                    }
                    coin++;
                }
                if (coin == 2 && !visited[nx1][ny1][nx2][ny2]) {
                    visited[nx1][ny1][nx2][ny2] = true;
                    queue.offer(new point(nx1, ny1, nx2, ny2, p.cnt + 1));
                } else if (coin == 1) {
                    System.out.println(p.cnt + 1);
                    System.exit(0);
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
        visited = new boolean[n][m][n][m];
        boolean first = true;
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = str.charAt(j);
                if (arr[i][j] == 'o') {
                    if (first) {
                        x1 = i;
                        y1 = j;
                    } else {
                        x2 = i;
                        y2 = j;
                    }
                    first = !first;
                }
            }
        }
        bfs();
        System.out.println(-1);
    }
}