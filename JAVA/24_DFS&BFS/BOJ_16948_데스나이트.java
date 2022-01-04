import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;
import java.util.StringTokenizer;

class point {
    int x, y;

    public point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {

    static int n, r1, r2, c1, c2;
    static int[][] arr;
    static boolean[][] visited;

    public static void bfs(int x, int y) {
        Queue<point> queue = new LinkedList<point>();
        queue.offer(new point(x, y));
        visited[x][y] = true;
        int[] dx = { -2, -2, 0, 0, 2, 2 };
        int[] dy = { -1, 1, -2, 2, -1, 1 };
        while (!queue.isEmpty()) {
            point p = queue.poll();
            if (p.x == r2 && p.y == c2) {
                System.out.println(arr[p.x][p.y]);
                System.exit(0);
            }
            for (int i = 0; i < 6; i++) {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && arr[nx][ny] == 0) {
                    visited[nx][ny] = true;
                    arr[nx][ny] = arr[p.x][p.y] + 1;
                    queue.offer(new point(nx, ny));
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n][n];
        visited = new boolean[n][n];
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        r1 = Integer.parseInt(st.nextToken());
        c1 = Integer.parseInt(st.nextToken());
        r2 = Integer.parseInt(st.nextToken());
        c2 = Integer.parseInt(st.nextToken());
        bfs(r1, c1);
        System.out.println(-1);
    }
}