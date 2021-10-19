import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    public static int tile(int n) {
        int f0 = 1;
        int f1 = 1;
        int sum = 1;
        for (int i = 1; i < n; i++) {
            sum = (f1 + f0) % 15746;
            f0 = f1;
            f1 = sum;
        }
        return sum;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        System.out.println(tile(n));
    }
}