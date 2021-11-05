import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[] arr;
    static int[] dp;

    static int wire(int n) {
        if (dp[n] == 1) {
            for (int i = n + 1; i < dp.length; i++) {
                if (arr[n] < arr[i]) {
                    dp[n] = Math.max(dp[n], wire(i) + 1);
                }
            }
        }
        return dp[n];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        dp = new int[501];
        arr = new int[501];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int tmp = Integer.parseInt(st.nextToken());
            dp[tmp] = 1;
            arr[tmp] = Integer.parseInt(st.nextToken());
        }
        int max = 0;
        for (int i = 0; i < dp.length; i++) {
            max = Math.max(wire(i), max);
        }
        System.out.println(n - max);
    }
}