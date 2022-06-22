import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    final static int INF = -3276800;

    static int n, m;
    static int[] sum;
    static Integer[][] dp;

    public static int split(int idx, int section) {
        if (section == 0) return 0;
        if (idx <= 0) return INF;
        if (dp[idx][section] == null) {
            dp[idx][section] = split(idx - 1, section);
            for (int i = idx; i > 0; i--) {
                dp[idx][section] = Math.max(dp[idx][section], split(i - 2, section - 1) + (sum[idx] - sum[i - 1]));
            }
        }
        return dp[idx][section];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        sum = new int[n + 1];
        dp = new Integer[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + Integer.parseInt(br.readLine());
        }
        System.out.println(split(n, m));
    }
}