import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, m;
    static int[][] matA, matB;

    public static void reverse(int r, int c) {
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                matA[i][j] = Math.abs(matA[i][j] - 1);
            }
        }
    }

    public static boolean check() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matA[i][j] != matB[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        matA = new int[n][m];
        matB = new int[n][m];
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                matA[i][j] = str.charAt(j) - '0';
            }
        }
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                matB[i][j] = str.charAt(j) - '0';
            }
        }
        int cnt = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                if (matA[i][j] != matB[i][j]) {
                    reverse(i, j);
                    cnt++;
                }
            }
        }
        if (check()) {
            System.out.println(cnt);
        } else {
            System.out.println(-1);
        }
    }
}