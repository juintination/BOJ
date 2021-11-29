import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, s, cnt = 0;
    static int[] arr;
    static boolean[] visited;

    public static void dfs(int dpth, int sum) {
        if (dpth == n) {
            if (sum == s) {
                boolean tst = false;
                for (int i = 0; i < n; i++) {
                    if (visited[i]) {
                        tst = true;
                        break;
                    }
                }
                if (tst) {
                    cnt++;
                }
            }
            return;
        }
        if (!visited[dpth]) {
            dfs(dpth + 1, sum);
            visited[dpth] = true;
            dfs(dpth + 1, sum + arr[dpth]);
            visited[dpth] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        arr = new int[n];
        visited = new boolean[n];
        s = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        dfs(0, 0);
        System.out.println(cnt);
    }
}