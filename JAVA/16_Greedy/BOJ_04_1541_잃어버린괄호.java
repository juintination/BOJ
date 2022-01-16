import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), "-");
        boolean first = true;
        int sum = 0;
        while (st.hasMoreTokens()) {
            int tmp = 0;
            StringTokenizer plus = new StringTokenizer(st.nextToken(), "+");
            while (plus.hasMoreTokens()) {
                tmp += Integer.parseInt(plus.nextToken());
            }
            if (first) {
                sum = tmp;
                first = !first;
            } else {
                sum -= tmp;
            }
        }
        System.out.println(sum);
    }
}