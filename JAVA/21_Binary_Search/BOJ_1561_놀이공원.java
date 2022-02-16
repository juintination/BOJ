import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] arr = new int[m];
        long max = 0;
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < m; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            max = Math.max(max, arr[i]);
        }
        if (n <= m) {
            System.out.println(n);
            return;
        }
        max *= n;
        long min = 0, time = 0;
        while (min <= max) {
            long mid = (max + min) / 2;
            long sum = m;
            for (int i = 0; i < m; i++) {
                sum += mid / arr[i];
            }
            if (sum >= n) {
                time = mid;
                max = mid - 1;
            } else if (sum < n) {
                min = mid + 1;
            }
        }
        long cnt = m;
        for (int i = 0; i < m; i++) {
            cnt += (time - 1) / arr[i];
        }
        for (int i = 0; i < m; i++) {
            if (time % arr[i] == 0) {
                cnt++;
            }
            if (cnt == n) {
                System.out.println(i + 1);
                return;
            }
        }
    }
}