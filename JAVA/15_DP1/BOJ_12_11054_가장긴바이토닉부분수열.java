import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[] arr;
    static Integer[] dp;
    static Integer[] dp2;

    public static int LIS(int n) {
        if (dp[n] == null) {
            dp[n] = 1;
            for (int i = n - 1; i >= 0; i--) {
                if (arr[i] < arr[n]) {
                    dp[n] = Math.max(dp[n], LIS(i) + 1);
                }
            }
        }
        return dp[n];
    }

    public static int LDS(int n) {
        if (dp2[n] == null) {
            dp2[n] = 1;
            for (int i = n + 1; i < dp2.length; i++) {
                if (arr[i] < arr[n]) {
                    dp2[n] = Math.max(dp2[n], LDS(i) + 1);
                }
            }
        }
        return dp2[n];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        arr = new int[n];
        dp = new Integer[n];
        dp2 = new Integer[n];
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        for (int i = 0; i < n; i++) {
            LIS(i);
            LDS(i);
        }
        int max = 1;
        for (int i = 0; i < n; i++) {
            max = Math.max(max, dp[i] + dp2[i]);
        }
        System.out.println(max - 1);
    }
}