import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
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
        return this.cnt - o.cnt;
    }

}

public class Main {

    static int w, h;
    static int[][][] mirror;
    static char[][] arr;
    static point start, end;

    public static void dijkstra() {
        PriorityQueue<point> queue = new PriorityQueue<>();
        queue.offer(start);
        int[] dx = { 1, 0, -1, 0 };
        int[] dy = { 0, 1, 0, -1 };
        while (!queue.isEmpty()) {
            point p = queue.poll();
            if (p.x == end.x && p.y == end.y) {
                end.cnt = p.cnt;
                return;
            }
            for (int i = 0; i < 4; i++) {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                if (0 <= nx && nx < h && 0 <= ny && ny < w && arr[nx][ny] != '*') {
                    if (p.i == i) {
                        if (p.cnt < mirror[i][nx][ny]) {
                            mirror[i][nx][ny] = p.cnt;
                            queue.offer(new point(nx, ny, i, p.cnt));                            }
                    } else if (Math.abs(p.i - i) != 2) {
                        if (p.cnt + 1 < mirror[i][nx][ny]) {
                            mirror[i][nx][ny] = p.cnt + 1;
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
        mirror = new int[4][h][w];
        for (int k = 0; k < 4; k++) {
            for (int i = 0; i < h; i++) {
                Arrays.fill(mirror[k][i], Integer.MAX_VALUE);
            }
        }
        for (int i = 0; i < h; i++) {
            String str = br.readLine();
            arr[i] = str.toCharArray();
            for (int j = 0; j < w; j++) {
                if (arr[i][j] == 'C') {
                    if (start == null) {
                        start = new point(i, j, -5, -1);
                    } else {
                        end = new point(i, j, -5, Integer.MAX_VALUE);
                    }
                }
            }
        }
        dijkstra();
        System.out.println(end.cnt);
    }
}