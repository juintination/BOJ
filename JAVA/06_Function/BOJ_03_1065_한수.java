import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static int hannum(int n) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (i < 100) cnt++;
            else {
                String str = Integer.toString(i);
                if (str.charAt(0) - str.charAt(1) == str.charAt(1) - str.charAt(2)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        System.out.println(hannum(n));
    }
}