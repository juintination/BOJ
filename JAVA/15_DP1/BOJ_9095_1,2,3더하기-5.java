import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    static Long[][] dp = new Long[100001][4];

    public static long plus(int n, int value) {
        if (value == 1 && dp[n][value] == null) {
            dp[n][1] = plus(n - 1, 2) + plus(n - 1, 3);
        } else if (value == 2 && dp[n][value] == null) {
            dp[n][2] = plus(n - 2, 1) + plus(n - 2, 3);
        } else if (value == 3 && dp[n][value] == null) {
            dp[n][3] = plus(n - 3, 2) + plus(n - 3, 1);
        }
        return dp[n][value] % 1000000009;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        dp[1][2] = dp[1][3] = dp[2][1] = dp[2][3] = 0L;
        dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1L;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());
            long result = 0;
            for (int j = 1; j <= 3; j++) {
                result += plus(n, j);
            }
            sb.append(result % 1000000009).append("\n");
        }
        System.out.println(sb);
    }
}