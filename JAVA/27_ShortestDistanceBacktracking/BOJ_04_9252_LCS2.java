import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str1 = br.readLine();
        String str2 = br.readLine();
        int x = str1.length(), y = str2.length();
        int[][] dp = new int[x + 1][y + 1];
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        sb.append(dp[x][y]).append("\n");
        Stack<Character> stack = new Stack<>();
        while (x > 0 && y > 0) {
            if (x == 0 || y == 0) break;
            if (dp[x][y] == dp[x - 1][y]) x--;
            else if (dp[x][y] == dp[x][y - 1]) y--;
            else {
                stack.push(str1.charAt(x - 1));
                x--;
                y--;
            }
        }
        while (!stack.isEmpty()) {
            sb.append(stack.pop());
        }
        System.out.println(sb);
    }
}