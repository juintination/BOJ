import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static int func5(int num) {
        int cnt = 0;
        while (num >= 5) {
            cnt += (num / 5);
            num /= 5;
        }
        return cnt;
    }

    public static int func2(int num) {
        int cnt = 0;
        while (num >= 2) {
            cnt += (num / 2);
            num /= 2;
        }
        return cnt;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int two = func2(n) - func2(n - m) - func2(m);
        int five = func5(n) - func5(n - m) - func5(m);
        System.out.println(Math.min(two, five));
    }
}