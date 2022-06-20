import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class point {
    int x, y, d;

    public point(int x, int y, int d) {
        this.x = x;
        this.y = y;
        this.d = d;
    }
}

public class Main {

    final static int horizontal = 0;
    final static int vertical = 1;
    final static int diagonal = 2;

    static int n, cnt = 0;
    static int[][] arr;

    public static boolean movePipe(point p, int dir) {
        if (dir == 0) {
            if (p.y + 1 < n && arr[p.x][p.y + 1] != 1) {
                return true;
            }
        } else if (dir == 1) {
            if (p.x + 1 < n && arr[p.x + 1][p.y] != 1) {
                return true;
            }
        } else if (dir == 2) {
            if (p.x + 1 < n && p.y + 1 < n && arr[p.x + 1][p.y] != 1 && arr[p.x][p.y + 1] != 1 && arr[p.x + 1][p.y + 1] != 1) {
                return true;
            }
        }
        return false;
    }

    public static void bfs() {
        Queue<point> queue = new LinkedList<>();
        queue.offer(new point(0, 1, 0));
        while (!queue.isEmpty()) {
            point p = queue.poll();
            if (p.x == n - 1 && p.y == n - 1) {
                cnt++;
                continue;
            }
            if (p.d == 0) {
                if (movePipe(p, 0)) {
                    queue.offer(new point(p.x, p.y + 1, 0));
                }
                if (movePipe(p, 2)) {
                    queue.offer(new point(p.x + 1, p.y + 1, 2));
                }
            } else if (p.d == 1) {
                if (movePipe(p, 1)) {
                    queue.offer(new point(p.x + 1, p.y, 1));
                }
                if (movePipe(p, 2)) {
                    queue.offer(new point(p.x + 1, p.y + 1, 2));
                }
            } else if (p.d == 2) {
                if (movePipe(p, 0)) {
                    queue.offer(new point(p.x, p.y + 1, 0));
                }
                if (movePipe(p, 1)) {
                    queue.offer(new point(p.x + 1, p.y, 1));
                }
                if (movePipe(p, 2)) {
                    queue.offer(new point(p.x + 1, p.y + 1, 2));
                }
            }
        }
    }

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n][n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        bfs();
        System.out.println(cnt);
    }
}