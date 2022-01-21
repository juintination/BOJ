import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(arr);
        int left = 0, right = n - 1, sum = 0;
        while (left < n - 1) {
            if (arr[left] < 1 && arr[left + 1] < 1) {
                sum += arr[left] * arr[left + 1];
            } else {
                break;
            }
            left += 2;
        }
        while (right > 0) {
            if (arr[right] > 1 && arr[right - 1] > 1) {
                sum += arr[right] * arr[right - 1];
            } else {
                break;
            }
            right -= 2;
        }
        for (int i = left; i <= right; i++) {
            sum += arr[i];
        }
        System.out.println(sum);
    }
}