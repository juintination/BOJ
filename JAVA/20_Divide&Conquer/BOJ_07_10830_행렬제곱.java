import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    final static int mod = 1000;

    static int n;
    static long b;
    static int[][] arr;

    public static int[][] multiply(int[][] o1, int[][] o2) {
        int[][] tmp = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    tmp[i][j] += o1[i][k] * o2[k][j];
                    tmp[i][j] %= mod;
                }
            }
        }
        return tmp;
    }

    public static int[][] pow(int[][] mat, long exp) {
        if (exp == 1) {
            return arr;
        }
        int[][] tmp = pow(mat, exp / 2);
        tmp = multiply(tmp, tmp);
        if (exp % 2 == 1) {
            tmp = multiply(tmp, arr);
        }
        return tmp;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        b = Long.parseLong(st.nextToken());
        arr = new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken()) % mod;
            }
        }
        arr = pow(arr, b);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sb.append(arr[i][j]).append(" ");
            }
            sb.append("\n");
        }
        System.out.print(sb);
    }
}