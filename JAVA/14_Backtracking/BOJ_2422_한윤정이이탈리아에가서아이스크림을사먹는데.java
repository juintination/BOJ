import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, m, cnt = 0;
    static int[] arr = new int[3];
    static boolean[][] mixed;

    public static void dfs(int dpth, int idx) {
        if (dpth == 3) {
            for (int i = 0; i < 3; i++) {
                if (mixed[arr[i]][arr[(i + 1) % 3]]) {
                    return;
                }
            }
            cnt++;
            return;
        }
        for (int i = idx; i <= n; i++) {
            arr[dpth] = i;
            dfs(dpth + 1, i + 1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        mixed = new boolean[n + 1][n + 1];
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            mixed[x][y] = mixed[y][x] = true;
        }
        dfs(0, 1);
        System.out.println(cnt);
    }
}