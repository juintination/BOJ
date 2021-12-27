import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int h = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken()); //The value of the local variable w is not used
            int n = Integer.parseInt(st.nextToken());
            int H = 1, W = 1;
            while (true) {
                if (n > h) {
                    W++;
                    n -= h;
                } else {
                    while (n != 0) {
                        n--;
                        H++;
                    }
                    sb.append((H - 1) * 100 + W).append("\n");
                    break;
                }
            }
        }
        System.out.print(sb);
    }
}