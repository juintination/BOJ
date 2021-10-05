import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int c = Integer.parseInt(br.readLine());
        double avg = 0;
        double cnt[] = new double[c];
        double per[] = new double[c];
        for (int i = 0; i < c; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int n = Integer.parseInt(st.nextToken());
            int score[] = new int[n];
            for (int j = 0; j < n; j++) {
                score[j] = Integer.parseInt(st.nextToken());
                avg += score[j];
            }
            avg /= n;
            for (int k = 0; k < n; k++) {
                if (score[k] > avg) cnt[i]++;
            }
            per[i] = cnt[i] / n * 100;
            avg = 0;
        }
        for (int i = 0; i < c; i++) {
            System.out.printf("%.3f%%\n", per[i]);
        }
    }
}