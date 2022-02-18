import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int two = 0, five = 0;
        for (int i = n; i > 0; i--) {
            int tmp = i;
            while (true) {
                if (tmp % 2 != 0 && tmp % 5 != 0) break;
                if (tmp % 2 == 0) {
                    tmp /= 2;
                    two++;
                }
                if (tmp % 5 == 0) {
                    tmp /= 5;
                    five++;
                }
            }
        }
        System.out.println(Math.min(two, five));
    }
}