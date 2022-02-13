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
        st = new StringTokenizer(br.readLine(), " ");
        int high = 0, low = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            high = Math.max(high, arr[i]);
            low = Math.min(low, arr[i]);
        }
        int left = 0, right = high - low, result = right;
        while (left <= right) {
            int mid = (right + left) / 2;
            int max = arr[0], min = arr[0], cnt = 1;
            for (int i = 1; i < n; i++) {
                max = Math.max(max, arr[i]);
                min = Math.min(min, arr[i]);
                if (max - min > mid) {
                    max = min = arr[i];
                    cnt++;
                }
            }
            if (cnt <= m) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        System.out.println(result);
    }
}