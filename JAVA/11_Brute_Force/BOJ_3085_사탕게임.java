import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    static char[][] candy;
    static int max;

    private static void swap(int x1, int y1, int x2, int y2) {
        char tmp = candy[x1][y1];
        candy[x1][y1] = candy[x2][y2];
        candy[x2][y2] = tmp;
    }

    public static void game() {
        for (int i = 0; i < candy.length; i++) {
            char color = candy[i][0];
            int cnt = 1;
            for (int j = 1; j < candy.length; j++) {
                if (color == candy[i][j]) {
                    cnt++;
                } else {
                    color = candy[i][j];
                    cnt = 1;
                }
                max = Math.max(max, cnt);
            }
        }
        for (int j = 0; j < candy.length; j++) {
            char color = candy[0][j];
            int cnt = 1;
            for (int i = 1; i < candy.length; i++) {
                if (color == candy[i][j]) {
                    cnt++;
                } else {
                    color = candy[i][j];
                    cnt = 1;
                }
                max = Math.max(max, cnt);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        candy = new char[n][n];
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < n; j++) {
                candy[i][j] = str.charAt(j);
            }
        }
        max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j < n - 1 && candy[i][j] != candy[i][j + 1]) {
                    swap(i, j, i, j + 1);
                    game();
                    swap(i, j, i, j + 1);
                }
                if (i < n - 1 && candy[i][j] != candy[i + 1][j]) {
                    swap(i, j, i + 1, j);
                    game();
                    swap(i, j, i + 1, j);
                }
            }
        }
        System.out.println(max);
    }
}