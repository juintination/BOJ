import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] tmp = new int[n];
        int sum = 0;
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; i++) {
            tmp[i] = Integer.parseInt(st.nextToken());
            int cnt = 0;
            for (int j = 1; j <= tmp[i]; j++) {
                if (tmp[i] % j == 0) {
                    cnt++;
                }
            }
            if (cnt == 2) {
                sum++;
            }
        }
        System.out.println(sum);
    }
}