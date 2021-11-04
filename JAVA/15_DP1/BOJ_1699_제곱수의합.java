import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    static int[] dp;

    static int square(int n) {
        if (dp[n] == 0) {
            dp[n] = n;
            for (int i = 2; i <= (int) Math.sqrt(n); i++) {
                dp[n] = Math.min(dp[n], square(n - (int) Math.pow(i, 2)) + 1);
            }
        }
        return dp[n];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        dp = new int[n + 1];
        dp[1] = 1;
        System.out.println(square(n));
    }
}