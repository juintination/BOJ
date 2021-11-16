import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        boolean[] broken = new boolean[10];
        if (m > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            while (m-- > 0) {
                broken[Integer.parseInt(st.nextToken())] = true;
            }
        }
        int min = Math.abs(n - 100);
        for (int i = 0; i <= 1000000; i++) {
            String str = String.valueOf(i);
            boolean tst = false;
            for (int j = 0; j < str.length(); j++) {
                if (broken[str.charAt(j) - '0'] == true) {
                    tst = !tst;
                    break;
                }
            }
            if (tst == false) {
                int tmp = str.length() + Math.abs(n - i);
                min = Math.min(tmp, min);
            }
        }
        System.out.println(min);
    }
}