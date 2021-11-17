import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int len = String.valueOf(n).length();
        int sum = 0;
        for (int i = 0; i < len - 1; i++) {
            sum += (9 * (int) Math.pow(10, i) * (i + 1));
        }
        sum += (len * (n - Math.pow(10, len - 1) + 1));
        System.out.println(sum);
    }
}