import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

    static int w, h, cnt;
    static int[][] arr;
    static boolean[][] visited;

    public static void bfs(int x, int y) {
        Queue<int[]> queue = new LinkedList<int[]>();
        queue.offer(new int[] { x, y });
        visited[x][y] = true;
        int[] dx = { -1, 0, 1, 0, 1, 1, -1, -1 };
        int[] dy = { 0, -1, 0, 1, -1, 1, 1, -1 };
        while (!queue.isEmpty()) {
            x = queue.peek()[0];
            y = queue.poll()[1];
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && arr[nx][ny] == 1) {
                    visited[nx][ny] = true;
                    queue.offer(new int[] { nx, ny });
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            w = Integer.parseInt(st.nextToken());
            h = Integer.parseInt(st.nextToken());
            if (w == 0 && h == 0) break;
            arr = new int[h][w];
            visited = new boolean[h][w];
            for (int i = 0; i < h; i++) {
                st = new StringTokenizer(br.readLine(), " ");
                for (int j = 0; j < w; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            cnt = 0;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (!visited[i][j] && arr[i][j] == 1) {
                        cnt++;
                        bfs(i, j);
                    }
                }
            }
            sb.append(cnt).append("\n");
        }
        System.out.print(sb);
    }
}