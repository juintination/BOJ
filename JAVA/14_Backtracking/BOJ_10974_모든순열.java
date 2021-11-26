import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    static int n;
    static int[] arr;
    static boolean[] visited;
    static StringBuilder sb;

    public static void dfs(int dpth) {
        if (dpth == n) {
            for (int i : arr) {
                sb.append(i).append(" ");
            }
            sb.append("\n");
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                arr[dpth] = i + 1;
                dfs(dpth + 1);
                visited[i] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        visited = new boolean[n];
        arr = new int[n];
        sb = new StringBuilder();
        dfs(0);
        System.out.print(sb);
    }
}