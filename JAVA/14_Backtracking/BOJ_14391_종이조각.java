import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, m, max;
    static int[][] arr;
    static boolean[][] visited;

    public static void dfs(int dpth, int idx) {
        if (dpth == n) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                int tmp = 0;
                for (int j = 0; j < m; j++) {
                    if (visited[i][j]) {
                        tmp = tmp * 10 + arr[i][j];
                    } else {
                        sum += tmp;
                        tmp = 0;
                    }
                }
                sum += tmp;
            }
            for (int i = 0; i < m; i++) {
                int tmp = 0;
                for (int j = 0; j < n; j++) {
                    if (!visited[j][i]) {
                        tmp = tmp * 10 + arr[j][i];
                    } else {
                        sum += tmp;
                        tmp = 0;
                    }
                }
                sum += tmp;
            }
            max = Math.max(max, sum);
            return;
        }
        if (idx == m) {
            dfs(dpth + 1, 0);
            return;
        }
        dfs(dpth, idx + 1);
        visited[dpth][idx] = true;
        dfs(dpth, idx + 1);
        visited[dpth][idx] = false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n][m];
        visited = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = str.charAt(j) - '0';
            }
        }
        max = 0;
        dfs(0, 0);
        System.out.println(max);
    }
}