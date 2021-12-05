import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    static int n, cnt;
    static int[] arr;
    static boolean[] visited;

    public static void dfs(int dpth) {
        if (dpth == n) {
            cnt++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                arr[dpth] = i;
                visited[i] = true;
                boolean tst = true;
                for (int j = 1; j <= dpth; j++) {
                    if (Math.abs(arr[dpth] - arr[dpth - j]) == j) {
                        tst = false;
                        break;
                    }
                }
                if (tst) {
                    dfs(dpth + 1);
                }
                visited[i] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n];
        visited = new boolean[n];
        cnt = 0;
        dfs(0);
        System.out.println(cnt);
    }
}