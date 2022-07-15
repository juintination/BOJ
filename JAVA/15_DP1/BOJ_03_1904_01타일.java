import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    static int[] dp;

    public static int tile(int n) {
        if (dp[n] == -1) {
            dp[n] = (tile(n - 1) + tile(n - 2)) % 15746;
        }
        return dp[n];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        dp = new int[n + 1];
        if (n > 2) {
            Arrays.fill(dp, -1);
            for (int i = 0; i <= 2; i++) {
                dp[i] = i;
            }
            System.out.println(tile(n));
        } else {
            System.out.println(n);
        }
    }
}