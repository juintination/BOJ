import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int n = Integer.parseInt(st.nextToken());
            int[] q = new int[n];
            int m = Integer.parseInt(st.nextToken());
            int cnt = 1, front = 0;
            st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < n; j++) {
                q[j] = Integer.parseInt(st.nextToken());
            }
            int max = 0;
            while (true) {
                for (int k = 0; k < n; k++) {
                    if (q[k] > max) max = q[k];
                }
                while (q[front] != max) {
                    front = (front + 1) % n;
                }
                if (front == m) break;
                q[front] = 0;
                max = 0;
                cnt++;
            }
            sb.append(cnt).append("\n");
        }
        System.out.println(sb);
    }
}