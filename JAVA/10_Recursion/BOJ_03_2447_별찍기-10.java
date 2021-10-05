import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {

    static char star[][];
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        star = new char[n][n];
        point(n, 0, 0);
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                bw.write(star[i][j]);
            }
            bw.newLine();
        }
        bw.flush();
        bw.close();
    }

    public static void point(int n, int x, int y) {
        if (n == 3) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    star[x + i][y + j] = '*';
                    if ((n - i) % 3 == 2 && (n - j) % 3 == 2) {
                        star[x + i][y + j] = ' ';
                    }
                }
            }
        } else {
            for (int i = 0; i < n; i = i + 3 * (n / 9)) {
                for (int j = 0; j < n; j = j + 3 * (n / 9)) {
                    point(n / 3, x + i, y + j);
                    if (i >= n / 3 && j >= n / 3 && i <= n / 3 * 2 - 1 && j <= n / 3 * 2 - 1) {
                        for (int k = n / 3; k <= n / 3 * 2 - 1; k++) {
                            for (int l = n / 3; l <= n / 3 * 2 - 1; l++) {
                                star[x + k][y + l] = ' ';
                            }
                        }
                    }
                }
            }
        }
    }
}