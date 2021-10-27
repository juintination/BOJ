import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    static Integer[][] dp;
    static int n;

    public static int stair(int cursor, int value) {
        if (cursor == n) {
            return dp[cursor][value];
        }
        if (dp[cursor][value] == null) {
            if (value == 0) {
                dp[cursor][value] = stair(cursor + 1, 1);
            } else if (value == 9) {
                dp[cursor][value] = stair(cursor + 1, 8);
            } else {
                dp[cursor][value] = stair(cursor + 1, value - 1) + stair(cursor + 1, value + 1);
            }
        }
        return dp[cursor][value] % 1000000000;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        dp = new Integer[n + 1][10];
        for (int i = 0; i < 10; i++) {
            dp[n][i] = 1;
        }
        int result = 0;
        for (int i = 1; i <= 9; i++) {
            result = (result + stair(1, i)) % 1000000000;
        }
        System.out.println(result % 1000000000);
    }
}