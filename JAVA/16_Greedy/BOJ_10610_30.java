import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int n = str.length();
        int[] arr = new int[n];
        boolean tst = false;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = str.charAt(i) - '0';
            if (arr[i] == 0) {
                tst = true;
            }
            sum += arr[i];
        }
        if (sum % 3 != 0) {
            tst = false;
        }
        if (tst) {
            Arrays.sort(arr);
            StringBuilder sb = new StringBuilder();
            for (int i = n - 1; i >= 0; i--) {
                sb.append(arr[i]);
            }
            System.out.println(sb);
        } else {
            System.out.println(-1);
        }
    }
}