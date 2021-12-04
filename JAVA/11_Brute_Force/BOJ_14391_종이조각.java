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
        int[][] arr = new int[n][m];
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = str.charAt(j) - '0';
            }
        }
        int max = 0;
        for (int i = 0; i < (1 << n * m); i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                int tmp = 0;
                for (int k = 0; k < m; k++) {
                    int l = j * m + k;
                    if ((i & (1 << l)) == 0) {
                        tmp = tmp * 10 + arr[j][k];
                    } else {
                        sum += tmp;
                        tmp = 0;
                    }
                }
                sum += tmp;
            }
            for (int j = 0; j < m; j++) {
                int tmp = 0;
                for (int k = 0; k < n; k++) {
                    int l = j + m * k;
                    if ((i & (1 << l)) != 0) {
                        tmp = tmp * 10 + arr[k][j];
                    } else {
                        sum += tmp;
                        tmp = 0;
                    }
                }
                sum += tmp;
            }
            max = Math.max(max, sum);
        }
        System.out.println(max);
    }
}