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
        int[] arr = new int[n];
        int max = 0, min = 0;
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            min = Math.max(min, arr[i]);
            max += arr[i];
        }
        int result = Integer.MAX_VALUE;
        while (min <= max) {
            int mid = (max + min) / 2;
            int sum = 0, cnt = 1;
            for (int i = 0; i < n; i++) {
                if (sum + arr[i] <= mid) {
                    sum += arr[i];
                } else {
                    sum = arr[i];
                    cnt++;
                }
            }
            if (cnt <= m) {
                result = mid;
                max = mid - 1;
            } else {
                min = mid + 1;
            }
        }
        System.out.println(result);
    }
}