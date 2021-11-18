import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    static int[] dp;

    public static int tile(int n) {
        if (dp[n] == 0) {
            dp[n] = tile(n - 2) * 3;
            for (int i = 4; i <= n; i += 2) {
                dp[n] += tile(n - i) * 2;
            }
        }
        return dp[n];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if (n % 2 != 0) System.out.println(0);
        else {
            dp = new int[n + 1];
            dp[0] = 1;
            tile(n);
            System.out.println(dp[n]);
        }
    }
}