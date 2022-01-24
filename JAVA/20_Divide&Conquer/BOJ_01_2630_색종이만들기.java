import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int white, blue;
    static int[][] arr;

    public static boolean coleredPaper(int x, int y, int size) {
        int color = arr[x][y];
        for (int i = x; i < x + size; i++) {
            for (int j = y; j < y + size; j++) {
                if (arr[i][j] != color) {
                    return false;
                }
            }
        }
        return true;
    }

    public static void quadTree(int x, int y, int size) {
        if (coleredPaper(x, y, size)) {
            if (arr[x][y] == 0) {
                white++;
            } else {
                blue++;
            }
            return;
        }
        size /= 2;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                quadTree(x + i * size, y + j * size, size);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        arr = new int[n][n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        white = blue = 0;
        quadTree(0, 0, n);
        StringBuilder sb = new StringBuilder();
        sb.append(white).append("\n").append(blue);
        System.out.println(sb);
    }
}