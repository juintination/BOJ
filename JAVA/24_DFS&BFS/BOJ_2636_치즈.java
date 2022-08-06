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

    static int n, m, cnt = 0;
    static int[][] arr;
    static boolean[][] visited;

    public static void bfs(int x, int y) {
        Queue<point> queue = new LinkedList<>();
        queue.offer(new point(x, y));
        visited = new boolean[n][m];
        visited[x][y] = true;
        int[] dx = { -1, 0, 1, 0 };
        int[] dy = { 0, -1, 0, 1 };
        while (!queue.isEmpty()) {
            point p = queue.poll();
            for (int i = 0; i < 4; i++) {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    if (arr[nx][ny] == 0) {
                        queue.offer(new point(nx, ny));
                    } else {
                        arr[nx][ny] = 0;
                        cnt--;
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
        arr = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                cnt = arr[i][j] == 1 ? cnt + 1 : cnt;
            }
        }
        StringBuilder sb = new StringBuilder();
        int preCnt = cnt, hour = 1;
        while (true) {
            bfs(0, 0);
            if (cnt == 0) {
                sb.append(hour).append("\n").append(preCnt);
                System.out.println(sb);
                break;
            }
            preCnt = cnt;
            hour++;
        }
    }
}