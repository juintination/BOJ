import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] arr = new int[9];
        int sum = 0;
        for (int i = 0; i < 9; i++) {
            arr[i] = Integer.parseInt(br.readLine());
            sum += arr[i];
        }
        boolean tst = true;
        for (int i = 0; i < 9; i++) {
            for (int j = i + 1; j < 9; j++) {
                int tmp = arr[i] + arr[j];
                if (sum - tmp == 100) {
                    arr[i] = arr[j] = 0;
                    tst = !tst;
                    break;
                }
            }
            if (tst == false) {
                break;
            }
        }
        Arrays.sort(arr);
        StringBuilder sb = new StringBuilder();
        for (int i = 2; i < 9; i++) {
            sb.append(arr[i]).append("\n");
        }
        System.out.print(sb);
    }
}