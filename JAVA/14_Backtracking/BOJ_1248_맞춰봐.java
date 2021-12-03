import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    static int n;
    static int[] arr;
    static char[][] sign;
    static StringBuilder sb;

    public static boolean check(int dpth) {
        int sum = 0;
        for (int i = dpth; i >= 0; i--) {
            sum += arr[i];
            if (sign[i][dpth] == '+' && sum <= 0) {
                return false;
            } else if (sign[i][dpth] == '-' && sum >= 0) {
                return false;
            } else if (sign[i][dpth] == '0' && sum != 0) {
                return false;
            }
        }
        return true;
    }

    public static void dfs(int dpth) {
        if (dpth == n) {
            for (int i = 0; i < n; i++) {
                sb.append(arr[i]).append(" ");
            }
            System.out.print(sb);
            System.exit(0);
        }
        for (int i = 0; i <= 20; i++) {
            arr[dpth] = i - 10;
            if (check(dpth)) {
                dfs(dpth + 1);
            }
            arr[dpth] = 0;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n];
        sign = new char[n][n];
        int cnt = 0;
        String str = br.readLine();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                sign[i][j] = str.charAt(cnt++);
            }
        }
        sb = new StringBuilder();
        dfs(0);
    }
}