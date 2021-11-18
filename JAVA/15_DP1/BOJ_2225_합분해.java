import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[][] dp;

    public static int decomposition(int n, int k) {
        if (k == 1) {
            dp[n][k] = 1;
        } else if (dp[n][k] == 0) {
            for (int i = n; i >= 0; i--) {
                dp[n][k] += decomposition(i, k - 1);
                dp[n][k] %= 1000000000;
            }
        }
        return dp[n][k];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        dp = new int[n + 1][k + 1];
        System.out.println(decomposition(n, k));
    }
}