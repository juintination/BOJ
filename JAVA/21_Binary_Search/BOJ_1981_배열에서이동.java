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

    static int n;
    static int[][] arr;
    static boolean[][] visited;

    public static boolean bfs(int min, int max) {
        Queue<point> queue = new LinkedList<>();
        queue.offer(new point(0, 0));
        visited[0][0] = true;
        int[] dx = { -1, 0, 1, 0 };
        int[] dy = { 0, -1, 0, 1 };
        while (!queue.isEmpty()) {
            point p = queue.poll();
            if (p.x == n - 1 && p.y == n - 1) {
                return true;
            }
            for (int i = 0; i < 4; i++) {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                    if (min <= arr[nx][ny] && arr[nx][ny] <= max) {
                        queue.offer(new point(nx, ny));
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n][n];
        int max = 0, min = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                max = Math.max(max, arr[i][j]);
                min = Math.min(min, arr[i][j]);
            }
        }
        int left = 0, right = max - min, result = right;
        while (left <= right) {
            int mid = (right + left) / 2;
            boolean tst = false;
            for (int idx = min; idx <= max; idx++) {
                if (idx <= arr[0][0] && arr[0][0] <= idx + mid) {
                    visited = new boolean[n][n];
                    if (bfs(idx, idx + mid)) {
                        tst = true;
                        break;
                    }
                }
            }
            if (tst) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        System.out.println(result);
    }
}