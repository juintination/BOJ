import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int cnt = 1, sum = 0;
        while (true) {
            sum += cnt;
            if (n <= sum) {
                if (cnt % 2 == 1) {
                    System.out.println((sum - n + 1) + "/" + (cnt + n - sum));
                } else {
                    System.out.println((cnt + n - sum) + "/" + (sum - n + 1));
                }
                break;
            }
            cnt++;
        }
    }
}