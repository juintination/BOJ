import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int n;
    static long[] b, arr;
    static boolean[] visited;

    public static void dfs(int idx, int dpth) {
        if (!visited[idx]) {
            visited[idx] = true;
            arr[dpth] = b[idx];
            if (dpth == n - 1) {
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < n; i++) {
                    sb.append(arr[i]).append(" ");
                }
                System.out.println(sb);
                System.exit(0);
            }
            if (arr[dpth] % 3 == 0) {
                for (int i = idx - 1; i >= 0; i--) {
                    if (b[i] == arr[dpth] / 3) {
                        dfs(i, dpth + 1);
                    }
                }
            }
            for (int i = idx + 1; i < n; i++) {
                if (b[i] == arr[dpth] * 2) {
                    dfs(i, dpth + 1);
                }
            }
            visited[idx] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        b = new long[n];
        arr = new long[n];
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; i++) {
            b[i] = Long.parseLong(st.nextToken());
        }
        Arrays.sort(b);
        visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            dfs(i, 0);
            Arrays.fill(visited, false);
        }
    }
}