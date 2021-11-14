import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static Integer[][] dp;
    static int[] weight;
    static int[] value;

    public static int knapsack(int n, int k) {
        if (dp[n][k] == null) {
            if (weight[n] > k) {
                dp[n][k] = knapsack(n - 1, k);
            } else {
                dp[n][k] = Math.max(knapsack(n - 1, k), knapsack(n - 1, k - weight[n]) + value[n]);
            }
        }
        return dp[n][k];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        dp = new Integer[n + 1][k + 1];
        weight = new int[n + 1];
        value = new int[n + 1];
        for (int i = 0; i <= k; i++) {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            weight[i] = Integer.parseInt(st.nextToken());
            value[i] = Integer.parseInt(st.nextToken());
        }
        System.out.println(knapsack(n, k));
    }
}