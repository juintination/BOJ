import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    final static int left = 1;
    final static int right = 2;

    static int[][] dp;

    static int zoo(int n, int direction) {
        if (dp[n][direction] == 0) {
            if (direction == 0) {
                dp[n][0] = (zoo(n - 1, 0) + zoo(n - 1, 1) + zoo(n - 1, 2)) % 9901;
            } else if (direction == 1) {
                dp[n][1] = (zoo(n - 1, 0) + zoo(n - 1, 2)) % 9901;
            } else {
                dp[n][2] = (zoo(n - 1, 0) + zoo(n - 1, 1)) % 9901;
            }
        }
        return dp[n][direction] % 9901;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        dp = new int[n + 1][3];
        dp[1][0] = dp[1][1] = dp[1][2] = 1;
        int result = zoo(n, 0) + zoo(n, 1) + zoo(n, 2);
        System.out.println(result % 9901);
    }
}