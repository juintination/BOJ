import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;
import java.util.ArrayList;
import java.util.StringTokenizer;

class point {
    int x, y, cnt;

    public point(int x, int y, int cnt) {
        this.x = x;
        this.y = y;
        this.cnt = cnt;
    }
}

public class Main {

    static int n, m, wall = 0;
    static int min = Integer.MAX_VALUE;
    static int[][] arr;
    static point[] virus;
    static ArrayList<point> list;

    public static void dfs(int dpth, int idx) {
        if (dpth == m) {
            bfs();
            return;
        }
        for (int i = idx; i < list.size(); i++) {
            point p = list.get(i);
            virus[dpth] = p;
            dfs(dpth + 1, i + 1);
            virus[dpth] = null;
        }
    }

    public static void bfs() {
        Queue<point> queue = new LinkedList<point>();
        boolean[][] visited = new boolean[n][n];
        for (point v : virus) {
            queue.offer(v);
            visited[v.x][v.y] = true;
        }
        int[] dx = { -1, 0, 1, 0 };
        int[] dy = { 0, -1, 0, 1 };
        int size = m, cnt = 0;
        while (!queue.isEmpty()) {
            point p = queue.poll();
            cnt = Math.max(cnt, p.cnt);
            for (int i = 0; i < 4; i++) {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    if (!visited[nx][ny] && (arr[nx][ny] == 0 || arr[nx][ny] == 2)) {
                        queue.offer(new point(nx, ny, p.cnt + 1));
                        visited[nx][ny] = true;
                        size++;
                    }
                }
            }
        }
        int tmp = n * n - wall - size;
        if (tmp == 0) {
            min = Math.min(min, cnt);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n][n];
        virus = new point[m];
        list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (arr[i][j] == 2) {
                    list.add(new point(i, j, 0));
                } else if (arr[i][j] == 1) {
                    wall++;
                }
            }
        }
        dfs(0, 0);
        if (min == Integer.MAX_VALUE) {
            System.out.println(-1);
        } else {
            System.out.println(min);
        }
    }
}