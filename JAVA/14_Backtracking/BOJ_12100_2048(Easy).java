import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, max = 0;
    static int[] dir;
    static int[][] arr, tmp;
    static boolean[][] visited;

    public static void move(int i, int j, int k) {
        int[] dx = { -1, 0, 1, 0 };
        int[] dy = { 0, -1, 0, 1 };
        if (tmp[i][j] == 0) return;
        while (true) {
            int nx = i + dx[k], ny = j + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                if (tmp[nx][ny] == tmp[i][j]) {
                    visited[nx][ny] = true;
                    tmp[nx][ny] += tmp[i][j];
                    tmp[i][j] = 0;
                    break;
                } else if (tmp[nx][ny] != 0) {
                    break;
                }
                tmp[nx][ny] = tmp[i][j];
                tmp[i][j] = 0;
                i = nx;
                j = ny;
            } else break;
        }

    }

    public static void game() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tmp[i][j] = arr[i][j];
            }
        }
        for (int k = 0; k < 5; k++) {
            visited = new boolean[n][n];
            if (dir[k] == 0) {// 상(-1,0)
                for (int i = 1; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        move(i, j, dir[k]);
                    }
                }
            } else if (dir[k] == 1) {// 좌(0,-1)
                for (int j = 1; j < n; j++) {
                    for (int i = 0; i < n; i++) {
                        move(i, j, dir[k]);
                    }
                }
            } else if (dir[k] == 2) {// 하(1,0)
                for (int i = n - 2; i >= 0; i--) {
                    for (int j = 0; j < n; j++) {
                        move(i, j, dir[k]);
                    }
                }
            } else {// 우(0,1)
                for (int j = n - 2; j >= 0; j--) {
                    for (int i = 0; i < n; i++) {
                        move(i, j, dir[k]);
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                max = Math.max(max, tmp[i][j]);
            }
        }
    }

    public static void dfs(int dpth) {
        if (dpth == 5) {
            game();
            return;
        }
        for (int i = 0; i < 4; i++) {
            dir[dpth] = i;
            dfs(dpth + 1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n][n];
        tmp = new int[n][n];
        dir = new int[5];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        dfs(0);
        System.out.println(max);
    }
}