import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    static int[][] dp;

    public static int apt(int k, int n) {
        if(dp[k][n] == 0) {
            dp[k][n] = apt(k - 1, n) + apt(k, n - 1);
        }
        return dp[k][n];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        dp = new int[15][15];
        for (int i = 0; i < 15; i++) {
            dp[i][1] = 1;
            dp[0][i] = i;
        }
        StringBuilder sb = new StringBuilder();
        while (t-- > 0) {
            int k = Integer.parseInt(br.readLine());
            int n = Integer.parseInt(br.readLine());
            sb.append(apt(k, n)).append("\n");
        }
        System.out.print(sb);
    }
}