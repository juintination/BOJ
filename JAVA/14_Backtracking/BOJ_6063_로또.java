import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n;
    static int[] arr, lotto;
    static boolean[] visited;
    static StringBuilder sb;

    public static void dfs(int dpth) {
        if (dpth == 6) {
            for (int i = 0; i < 6; i++) {
                sb.append(arr[i]).append(" ");
            }
            sb.append("\n");
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (dpth > 0 && arr[dpth - 1] > lotto[i]) continue;
                visited[i] = true;
                arr[dpth] = lotto[i];
                dfs(dpth + 1);
                visited[i] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            n = Integer.parseInt(st.nextToken());
            if (n == 0) break;
            arr = new int[n];
            lotto = new int[n];
            visited = new boolean[n];
            for (int i = 0; i < n; i++) {
                lotto[i] = Integer.parseInt(st.nextToken());
            }
            dfs(0);
            sb.append("\n");
        }
        System.out.print(sb);
    }
}