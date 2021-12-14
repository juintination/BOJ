import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;
import java.util.StringTokenizer;

class tomato {
    int x;
    int y;
    int z;

    public tomato(int z, int x, int y) {
        this.z = z;
        this.x = x;
        this.y = y;
    }
}

public class Main {

    static int n, m, h;
    static int[][][] arr;

    public static void bfs(int x, int y, int z) {
        Queue<tomato> queue = new LinkedList<tomato>();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    if (arr[i][j][k] == 1) {
                        queue.offer(new tomato(i, j, k));
                    }
                }
            }
        }
        int[] dx = { -1, 0, 1, 0, 0, 0 };
        int[] dy = { 0, -1, 0, 1, 0, 0 };
        int[] dz = { 0, 0, 0, 0, -1, 1 };
        while (!queue.isEmpty()) {
            tomato t = queue.poll();
            z = t.z;
            y = t.y;
            x = t.x;
            for (int i = 0; i < 6; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nz = z + dz[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && nz >= 0 && nz < h && arr[nz][nx][ny] == 0) {
                    arr[nz][nx][ny] = arr[z][x][y] + 1;
                    queue.offer(new tomato(nz, nx, ny));
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        h = Integer.parseInt(st.nextToken());
        arr = new int[h][m][n];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < m; j++) {
                st = new StringTokenizer(br.readLine(), " ");
                for (int k = 0; k < n; k++) {
                    arr[i][j][k] = Integer.parseInt(st.nextToken());
                }
            }
        }
        bfs(0, 0, 0);
        int max = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    if (arr[i][j][k] == 0) {
                        System.out.println(-1);
                        System.exit(0);
                    }
                    max = Math.max(max, arr[i][j][k]);
                }
            }
        }
        System.out.println(max - 1);
    }
}