import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        int min = Integer.MAX_VALUE;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        if (n == 1) {
            System.out.println(0);
            System.exit(0);
        }
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int cnt = 0;
                if (i != 0) {
                    cnt++;
                }
                if (j != 0) {
                    cnt++;
                }
                int a0 = arr[0] + i, a1 = arr[1] + j;
                int d = a0 - a1, cur = a1;
                boolean tst = true;
                for (int k = 2; k < n; k++) {
                    cur -= d;
                    if (arr[k] == cur) {
                        continue;
                    } else if (arr[k] + 1 == cur || arr[k] - 1 == cur) {
                        cnt++;
                    } else {
                        tst = false;
                        break;
                    }
                }
                if (tst) {
                    min = Math.min(min, cnt);
                }
            }
        }
        if (min == Integer.MAX_VALUE) {
            System.out.println(-1);
        } else {
            System.out.println(min);
        }
    }
}