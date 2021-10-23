import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[][] arr;
    static Integer[][] dp;
    static int n;

    static int triangle(int x, int y) {
        if (dp[x][y] == null) {
            dp[x][y] = Math.max(triangle(x + 1, y), triangle(x + 1, y + 1)) + arr[x][y];
        }
        return dp[x][y];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n][n];
        dp = new Integer[n][n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j <= i; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for (int i = 0; i < n; i++) {
            dp[n - 1][i] = arr[n - 1][i];
        }
        System.out.println(triangle(0, 0));
    }
}