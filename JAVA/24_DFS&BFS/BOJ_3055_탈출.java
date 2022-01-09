import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;
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

    static int n, m, x, y;
    static char[][] arr;
    static boolean[][] visited, flooded;
    static Queue<int[]> water = new LinkedList<>();

    public static void bfs() {
        Queue<point> queue = new LinkedList<>();
        queue.offer(new point(x, y, 0));
        visited[x][y] = true;
        int turn = 0;
        boolean watered = false;
        int[] dx = { -1, 0, 1, 0 };
        int[] dy = { 0, -1, 0, 1 };
        while (!queue.isEmpty()) {
            point p = queue.poll();
            int size = water.size();
            while (size-- > 0) {
                if (turn > p.cnt) break;
                int wx = water.peek()[0];
                int wy = water.poll()[1];
                for (int i = 0; i < 4; i++) {
                    int nx = wx + dx[i];
                    int ny = wy + dy[i];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && !flooded[nx][ny]) {
                        if (arr[nx][ny] == '.' || arr[nx][ny] == 'S') {
                            water.offer(new int[] { nx, ny });
                            flooded[nx][ny] = true;
                            arr[nx][ny] = '*';
                        }
                    }
                }
                watered = true;
            }
            if (watered) {
                watered = false;
                turn++;
            }
            for (int i = 0; i < 4; i++) {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                    if (arr[nx][ny] == 'D') {
                        System.out.println(p.cnt + 1);
                        System.exit(0);
                    } else if (arr[nx][ny] == '.') {
                        queue.offer(new point(nx, ny, p.cnt + 1));
                        visited[nx][ny] = true;
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
        flooded = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = str.charAt(j);
                if (arr[i][j] == '*') {
                    water.offer(new int[] { i, j });
                    flooded[i][j] = true;
                } else if (arr[i][j] == 'S') {
                    x = i;
                    y = j;
                }
            }
        }
        bfs();
        System.out.println("KAKTUS");
    }
}