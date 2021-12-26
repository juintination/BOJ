import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;
import java.util.ArrayList;
import java.util.StringTokenizer;

class point {
    int x;
    int y;

    public point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {

    static int n, m, wall;
    static int result = 0;
    static int[][] arr;
    static ArrayList<point> virus;

    public static void dfs(int dpth) {
        if (dpth == 3) {
            bfs();
            return;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 0) {
                    arr[i][j] = 1;
                    dfs(dpth + 1);
                    arr[i][j] = 0;
                }
            }
        }
    }

    public static void bfs() {
        Queue<point> queue = new LinkedList<point>();
        boolean[][] visited = new boolean[n][m];
        for (point v : virus) {
            queue.offer(v);
            visited[v.x][v.y] = true;
        }
        int size = virus.size();
        int[] dx = { -1, 0, 1, 0 };
        int[] dy = { 0, -1, 0, 1 };
        while (!queue.isEmpty()) {
            point p = queue.poll();
            for (int i = 0; i < 4; i++) {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && arr[nx][ny] == 0) {
                    queue.offer(new point(nx, ny));
                    visited[nx][ny] = true;
                    size++;
                }
            }
        }
        int tmp = n * m - wall - size;
        result = Math.max(result, tmp);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n][m];
        virus = new ArrayList<>();
        wall = 3;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (arr[i][j] == 2) {
                    virus.add(new point(i, j));
                } else if (arr[i][j] == 1) {
                    wall++;
                }
            }
        }
        dfs(0);
        System.out.println(result);
    }
}