import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    static String str1;
    static String str2;
    static Integer[][] dp;

    static int LCS(int x, int y) {
        if (x == -1 || y == -1) {
            return 0;
        }
        if (dp[x][y] == null) {
            if (str1.charAt(x) == str2.charAt(y)) {
                dp[x][y] = LCS(x - 1, y - 1) + 1;
            } else {
                dp[x][y] = Math.max(LCS(x - 1, y), LCS(x, y - 1));
            }
        }
        return dp[x][y];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        str1 = br.readLine();
        str2 = br.readLine();
        dp = new Integer[str1.length()][str2.length()];
        System.out.println(LCS(str1.length() - 1, str2.length() - 1));
    }
}