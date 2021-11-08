import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[][] arr;
    static Integer[][] dp;
    static int max;

    public static int sticker(int n, int k) {
        if (dp[n][k] == null) {
            if (k == 0) {
                dp[n][k] = Math.max(sticker(n - 1, 1), sticker(n - 2, 1)) + arr[n][k];
            } else {
                dp[n][k] = Math.max(sticker(n - 1, 0), sticker(n - 2, 0)) + arr[n][k];
            }
        }
        return dp[n][k];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            arr = new int[n + 1][2];
            dp = new Integer[n + 1][2];
            for (int i = 0; i < 2; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine(), " ");
                for (int j = 1; j <= n; j++) {
                    arr[j][i] = Integer.parseInt(st.nextToken());
                }
            }
            dp[0][0] = dp[0][1] = 0;
            dp[1][0] = arr[1][0];
            dp[1][1] = arr[1][1];
            sb.append(Math.max(sticker(n, 0), sticker(n, 1))).append("\n");
        }
        System.out.print(sb);
    }
}