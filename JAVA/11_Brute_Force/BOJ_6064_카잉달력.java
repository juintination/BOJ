import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int m = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken()) % n;
            int cnt = 0;
            while (true) {
                int year = m * cnt + x;
                // year % m = x, year % n = y
                if (year % n == y) {
                    sb.append(year).append("\n");
                    break;
                }
                if (year > m * n) {
                    sb.append(-1).append("\n");
                    break;
                }
                cnt++;
            }
        }
        System.out.print(sb);
    }
}