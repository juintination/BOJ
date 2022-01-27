import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {

    static char arr[][];

    public static void point(int x, int y, int size) {
        if (size == 3) {
            arr[x][y] = '*';
            arr[x + 1][y - 1] = arr[x + 1][y + 1] = '*';
            for (int i = -2; i <= 2; i++) {
                arr[x + 2][y + i] = '*';
            }
        } else {
            size /= 2;
            point(x, y, size);
            point(x + size, y + size, size);
            point(x + size, y - size, size);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        arr = new char[n][2 * n - 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2 * n - 1; j++) {
                arr[i][j] = ' ';
            }
        }
        point(0, n - 1, n);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            sb.append(arr[i]).append("\n");
        }
        System.out.println(sb);
    }
}