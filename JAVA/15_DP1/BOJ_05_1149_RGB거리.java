import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    final static int red = 0;
    final static int green = 1;
    final static int blue = 2;

    static int[][] cost;
    static int[][] dp;

    public static int paint(int n, int color) {
        if (dp[n][color] == 0) {
            if (color == 0) {
                dp[n][0] = Math.min(paint(n - 1, 1), paint(n - 1, 2)) + cost[n][0];
            } else if (color == 1) {
                dp[n][1] = Math.min(paint(n - 1, 0), paint(n - 1, 2)) + cost[n][1];
            } else {
                dp[n][2] = Math.min(paint(n - 1, 0), paint(n - 1, 1)) + cost[n][2];
            }
        }
        return dp[n][color];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        cost = new int[n][3];
        dp = new int[n][3];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            cost[i][0] = Integer.parseInt(st.nextToken());
            cost[i][1] = Integer.parseInt(st.nextToken());
            cost[i][2] = Integer.parseInt(st.nextToken());
        }
        dp[0][0] = cost[0][0];
        dp[0][1] = cost[0][1];
        dp[0][2] = cost[0][2];
        System.out.println(Math.min(paint(n - 1, 0), Math.min(paint(n - 1, 1), paint(n - 1, 2))));
    }
}