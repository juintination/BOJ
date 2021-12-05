import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[][] arr;
    static StringBuilder sb;

    public static boolean sudoku(int dpth, int idx, int value) {
        for (int i = 0; i < 9; i++) {
            if (arr[dpth][i] == value) {
                return false;
            }
            if (arr[i][idx] == value) {
                return false;
            }
        }
        int row = (dpth / 3) * 3;
        int col = (idx / 3) * 3;
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if (arr[i][j] == value) {
                    return false;
                }
            }
        }
        return true;
    }

    public static void dfs(int dpth, int idx) {
        if (idx == 9) {
            dfs(dpth + 1, 0);
            return;
        }
        if (dpth == 9) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    sb.append(arr[i][j]).append(' ');
                }
                sb.append('\n');
            }
            System.out.print(sb);
            System.exit(0);
        }
        if (arr[dpth][idx] == 0) {
            for (int i = 1; i <= 9; i++) {
                if (sudoku(dpth, idx, i)) {
                    arr[dpth][idx] = i;
                    dfs(dpth, idx + 1);
                }
            }
            arr[dpth][idx] = 0;
            return;
        }
        dfs(dpth, idx + 1);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        arr = new int[9][9];
        sb = new StringBuilder();
        for (int i = 0; i < 9; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < 9; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        dfs(0, 0);
    }
}