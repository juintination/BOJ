import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[] arr;
    static Integer[][] dp;
    static int max;

    public static int continous(int n) {
        if (dp[n][0] == null) {
            dp[n][0] = Math.max(continous(n - 1) + arr[n], arr[n]);
            max = Math.max(max, dp[n][0]);
        }
        return dp[n][0];
    }

    public static int continous2(int n) {
        if (dp[n][1] == null) {
            dp[n][1] = Math.max(continous2(n + 1) + arr[n], arr[n]);
        }
        return dp[n][1];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        arr = new int[n];
        dp = new Integer[n][2];
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        dp[0][0] = arr[0];
        dp[n - 1][1] = arr[n - 1];
        max = -1001;
        continous(n - 1);
        for (int i = 0; i < n; i++) {
            max = Math.max(max, dp[i][0]);
        }
        continous2(0);
        for (int i = 1; i < n - 1; i++) {
            max = Math.max(max, dp[i - 1][0] + dp[i + 1][1]);
        }
        System.out.println(max);
    }
}