import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    final static int p = 1000000007;

    public static long pow(long a, int b) {
        if (b == 1) {
            return a % p;
        }
        long tmp = pow(a, b / 2);
        if (b % 2 == 1) {
            return (tmp * tmp % p) * a % p;
        }
        return tmp * tmp % p;
    }

    public static long factorial(long n) {
        if (n <= 1) return 1;
        else return n * factorial(n - 1) % p;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        long numerator = factorial(n) % p;
        long denominator = factorial(k) * factorial(n - k) % p;
        System.out.println((numerator * pow(denominator, p - 2)) % p);
    }
}