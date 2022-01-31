import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int max = 0, min = Integer.MAX_VALUE;
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        while (n-- > 0) {
            int tmp = Integer.parseInt(st.nextToken());
            max = Math.max(max, tmp);
            min = Math.min(min, tmp);
        }
        System.out.println(max * min);
    }
}