import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int plus1 = 0;

    public static int makeZero(int a) {
        int mult2 = 0;
        while (a != 0) {
            if (a % 2 == 0) {
                a /= 2;
                mult2++;
            } else {
                a--;
                plus1++;
            }
        }
        return mult2;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            max = Math.max(max, makeZero(Integer.parseInt(st.nextToken())));
        }
        System.out.println(max + plus1);
    }
}