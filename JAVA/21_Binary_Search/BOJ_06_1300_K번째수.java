import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int k = Integer.parseInt(br.readLine());
        long min = 1, max = k, result = 0;
        while (min <= max) {
            long mid = (max + min) / 2;
            long cnt = 0;
            for (int i = 1; i <= n; i++) {
                cnt += Math.min(mid / i, n);
            }
            if (cnt >= k) {
                result = mid;
                max = mid - 1;
            } else {
                min = mid + 1;
            }
        }
        System.out.println(result);
    }
}