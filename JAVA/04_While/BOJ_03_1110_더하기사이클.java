import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = n, cnt = 0;
        while (true) {
            m = (((m % 10) * 10) + (m / 10 + m % 10) % 10);
            cnt++;
            if (m == n) break;
        }
        System.out.print(cnt);
    }
}