import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[] cnt = new int[3];
    static int[][] arr;

    public static boolean paper(int x, int y, int size) {
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
        if (paper(x, y, size)) {
            if (arr[x][y] == -1) {
                cnt[0]++;
            } else if (arr[x][y] == 0) {
                cnt[1]++;
            } else {
                cnt[2]++;
            }
            return;
        }
        size /= 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
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
        quadTree(0, 0, n);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 3; i++) {
            sb.append(cnt[i]).append("\n");
        }
        System.out.print(sb);
    }
}