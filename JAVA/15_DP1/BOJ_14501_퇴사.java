import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n;
    static int[][] arr;
    static Integer[] dp;

    public static int resign(int day) {
        if (dp[day] == null) {
            if (day + arr[day][0] > n) {
                return 0;
            }
            dp[day] = arr[day][1];
            for (int i = day + arr[day][0]; i < n; i++) {
                if (i + arr[i][0] <= n) {
                    dp[day] = Math.max(dp[day], arr[day][1] + resign(i));
                }
            }
        }
        return dp[day];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n][2];
        dp = new Integer[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
        }
        int max = 0;
        for (int i = 0; i < n; i++) {
            max = Math.max(max, resign(i));
        }
        System.out.println(max);
    }
}