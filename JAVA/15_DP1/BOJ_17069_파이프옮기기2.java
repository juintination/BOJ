import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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

    static int n;
    static int[][] arr;
    static Long[][][] dp;

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
            if (p.x + 1 < n && p.y + 1 < n && arr[p.x + 1][p.y] != 1 && arr[p.x][p.y + 1] != 1
                    && arr[p.x + 1][p.y + 1] != 1) {
                return true;
            }
        }
        return false;
    }

    public static long pipe(int x, int y, int d) {
        if (x == n - 1 && y == n - 1) {
            return 1;
        }
        if (dp[x][y][d] == null) {
            dp[x][y][d] = 0L;
            if (d == 0) {
                if (movePipe(new point(x, y, d), 0)) {
                    dp[x][y][d] += pipe(x, y + 1, 0);
                }
                if (movePipe(new point(x, y, d), 2)) {
                    dp[x][y][d] += pipe(x + 1, y + 1, 2);
                }
            } else if (d == 1) {
                if (movePipe(new point(x, y, d), 1)) {
                    dp[x][y][d] += pipe(x + 1, y, 1);
                }
                if (movePipe(new point(x, y, d), 2)) {
                    dp[x][y][d] += pipe(x + 1, y + 1, 2);
                }
            } else if (d == 2) {
                if (movePipe(new point(x, y, d), 0)) {
                    dp[x][y][d] += pipe(x, y + 1, 0);
                }
                if (movePipe(new point(x, y, d), 1)) {
                    dp[x][y][d] += pipe(x + 1, y, 1);
                }
                if (movePipe(new point(x, y, d), 2)) {
                    dp[x][y][d] += pipe(x + 1, y + 1, 2);
                }
            }
        }
        return dp[x][y][d];
    }

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n][n];
        dp = new Long[n][n][3];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        System.out.println(pipe(0, 1, 0));
    }
}