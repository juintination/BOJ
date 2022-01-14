import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;
import java.util.StringTokenizer;

class point {
    int rx, ry, bx, by, cnt;

    public point(int rx, int ry, int bx, int by, int cnt) {
        this.rx = rx;
        this.ry = ry;
        this.bx = bx;
        this.by = by;
        this.cnt = cnt;
    }
}

class marble {
    int x, y, cnt;

    public marble(int x, int y, int cnt) {
        this.x = x;
        this.y = y;
        this.cnt = cnt;
    }
}

public class Main {

    static int n, m, rx, ry, bx, by;
    static char[][] arr;
    static boolean[][][][] visited;

    public static marble tilt(int x, int y, int cnt, int i) {
        marble moved;
        int[] dx = { -1, 0, 1, 0 };
        int[] dy = { 0, -1, 0, 1 };
        while (true) {
            int nx = x + dx[i], ny = y + dy[i];
            if (arr[nx][ny] == '#' || arr[x][y] == 'O') break;
            x = nx;
            y = ny;
            cnt++;
        }
        moved = new marble(x, y, cnt);
        return moved;
    }

    public static void bfs() {
        Queue<point> queue = new LinkedList<>();
        queue.offer(new point(rx, ry, bx, by, 0));
        visited[rx][ry][bx][by] = true;
        int[] dx = { -1, 0, 1, 0 };
        int[] dy = { 0, -1, 0, 1 };
        while (!queue.isEmpty()) {
            point p = queue.poll();
            if (p.cnt >= 10) break;
            for (int i = 0; i < 4; i++) {
                marble nr = tilt(p.rx, p.ry, 0, i);
                marble nb = tilt(p.bx, p.by, 0, i);
                if (arr[nb.x][nb.y] == 'O') continue;
                if (arr[nr.x][nr.y] == 'O') {
                    System.out.println(1);
                    System.exit(0);
                }
                if (nr.x == nb.x && nr.y == nb.y) {
                    if (nr.cnt > nb.cnt) {
                        nr.x -= dx[i];
                        nr.y -= dy[i];
                    } else {
                        nb.x -= dx[i];
                        nb.y -= dy[i];
                    }
                }
                if (!visited[nr.x][nr.y][nb.x][nb.y]) {
                    visited[nr.x][nr.y][nb.x][nb.y] = true;
                    queue.offer(new point(nr.x, nr.y, nb.x, nb.y, p.cnt + 1));
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
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = str.charAt(j);
                if (arr[i][j] == 'R') {
                    rx = i;
                    ry = j;
                } else if (arr[i][j] == 'B') {
                    bx = i;
                    by = j;
                }
            }
        }
        bfs();
        System.out.println(0);
    }
}