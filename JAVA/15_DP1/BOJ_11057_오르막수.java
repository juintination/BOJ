import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    static int[][] dp;

    public static int ascent(int n, int k) {
        if (dp[n][k] == 0) {
            for (int i = 0; i <= k; i++) {
                dp[n][k] += ascent(n - 1, i);
                dp[n][k] %= 10007;
            }
        }
        return dp[n][k];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        dp = new int[n + 1][10];
        for (int i = 0; i < 10; i++) {
            dp[1][i] = 1;
        }
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            sum += ascent(n, i);
            sum %= 10007;
        }
        System.out.println(sum);
    }
}