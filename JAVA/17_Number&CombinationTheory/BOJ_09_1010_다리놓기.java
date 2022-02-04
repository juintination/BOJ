import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[][] dp = new int[30][30];

    public static int bridge(int m, int n) {
        if (dp[m][n] > 0) {
            return dp[m][n];
        }
        if (n == 0 || m == n) {
            return dp[m][n] = 1;
        }
        return dp[m][n] = bridge(m - 1, n - 1) + bridge(m - 1, n);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            sb.append(bridge(m, n)).append('\n');
        }
        System.out.print(sb);
    }
}