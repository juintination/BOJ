import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, min;
    static int[][] arr;
    static boolean[] visited;

    public static void dfs(int dpth, int idx) {
        if (dpth == n / 2) {
            int start = 0, link = 0;
            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (visited[i] && visited[j]) {
                        start += arr[i][j];
                        start += arr[j][i];
                    } else if (!visited[i] && !visited[j]) {
                        link += arr[i][j];
                        link += arr[j][i];
                    }
                }
            }
            min = Math.min(min, Math.abs(start - link));
            return;
        }
        for (int i = idx; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                dfs(dpth + 1, i + 1);
                visited[i] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n][n];
        visited = new boolean[n];
        for (int j = 0; j < n; j++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            for (int i = 0; i < n; i++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        min = Integer.MAX_VALUE;
        dfs(0, 0);
        System.out.println(min);
    }
}