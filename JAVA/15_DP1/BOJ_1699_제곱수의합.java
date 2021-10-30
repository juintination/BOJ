import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] dp = new int[n + 1];
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = i;
            for (int j = 2; j <= (int) Math.sqrt(i); j++) {
                dp[i] = Math.min(dp[i], dp[i - (int) Math.pow(j, 2)] + 1);
            }
        }
        System.out.println(dp[n]);
    }
}