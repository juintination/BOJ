import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class point implements Comparable<point> {
    int x, y, i, cnt;

    public point(int x, int y, int i, int cnt) {
        this.x = x;
        this.y = y;
        this.i = i;
        this.cnt = cnt;
    }

    @Override
    public int compareTo(point o) {
        return cnt - o.cnt;
    }

}

public class Main {

    static int w, h, x, y;
    static int[][] mirror;
    static char[][] arr;
    static point start;

    public static void bfs() {
        PriorityQueue<point> queue = new PriorityQueue<>();
        queue.offer(start);
        int[] dx = { 1, 0, -1, 0 };
        int[] dy = { 0, 1, 0, -1 };
        while (!queue.isEmpty()) {
            point p = queue.poll();
            if (p.x == x && p.y == y) {
                System.out.println(p.cnt);
                return;
            }
            for (int i = 0; i < 4; i++) {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && arr[nx][ny] == '.') {
                    if (p.i == i || p.i == -1) {
                        if (mirror[nx][ny] == 0 || p.cnt <= mirror[nx][ny]) {
                            mirror[nx][ny] = p.cnt;
                            queue.offer(new point(nx, ny, i, p.cnt));
                        }
                    } else {
                        if (mirror[nx][ny] == 0 || p.cnt + 1 <= mirror[nx][ny]) {
                            mirror[nx][ny] = p.cnt + 1;
                            queue.offer(new point(nx, ny, i, p.cnt + 1));
                        }
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        w = Integer.parseInt(st.nextToken());
        h = Integer.parseInt(st.nextToken());
        arr = new char[h][w];
        mirror = new int[h][w];
        for (int i = 0; i < h; i++) {
            String str = br.readLine();
            for (int j = 0; j < w; j++) {
                arr[i][j] = str.charAt(j);
                if (arr[i][j] == 'C') {
                    if (start == null) {
                        start = new point(i, j, -1, 0);
                    } else {
                        x = i;
                        y = j;
                        arr[i][j] = '.';
                    }
                }
            }
        }
        bfs();
    }
}