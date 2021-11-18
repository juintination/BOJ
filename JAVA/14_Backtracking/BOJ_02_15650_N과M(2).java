import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, m;
    static int[] arr;
    static boolean[] visited;
    static StringBuilder sb;

    public static void dfs(int dpth) {
        if (dpth == m) {
            for (int i : arr) {
                sb.append(i).append(" ");
            }
            sb.append("\n");
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (dpth > 0 && arr[dpth - 1] > i + 1) continue;
                visited[i] = !visited[i];
                arr[dpth] = i + 1;
                dfs(dpth + 1);
                visited[i] = !visited[i];
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        visited = new boolean[n];
        arr = new int[m];
        sb = new StringBuilder();
        dfs(0);
        System.out.print(sb);
    }
}