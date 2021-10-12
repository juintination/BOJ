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
        StringBuilder sb = new StringBuilder();
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
            sb.append(String.format("%.3f", cnt[i] / n * 100)).append('%').append('\n');
            avg = 0;
        }
        System.out.println(sb);
    }
}