import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    static Integer[] dp = new Integer[11];

    public static int plus(int n) {
        if (dp[n] == null) {
            dp[n] = plus(n - 1) + plus(n - 2) + plus(n - 3);
        }
        return dp[n];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < t; i++) {
            sb.append(plus(Integer.parseInt(br.readLine()))).append("\n");
        }
        System.out.println(sb);
    }
}