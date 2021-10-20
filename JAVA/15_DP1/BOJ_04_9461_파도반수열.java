import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    static Integer[] dp = new Integer[101];

    public static int wave(int n) {
        if (dp[n] == null) {
            dp[n] = wave(n - 2) + wave(n - 3);
        }
        return dp[n];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 1;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < t; i++) {
            sb.append(wave(Integer.parseInt(br.readLine()))).append("\n");
        }
        System.out.println(sb);
    }
}