import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, min;
    static int[] arr;
    static int[][] cost;
    static boolean[] visited;

    public static void dfs(int dpth) {
        if (dpth == n) {
            int sum = 0;
            for (int i = 1; i < n; i++) {
                if (cost[arr[i - 1]][arr[i]] != 0) {
                    sum += cost[arr[i - 1]][arr[i]];
                } else return;
            }
            if (cost[arr[n - 1]][arr[0]] != 0) {
                sum += cost[arr[n - 1]][arr[0]];
            } else return;
            min = Math.min(min, sum);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                arr[dpth] = i;
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
        cost = new int[n][n];
        for (int j = 0; j < n; j++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            for (int i = 0; i < n; i++) {
                cost[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        min = Integer.MAX_VALUE;
        dfs(0);
        System.out.println(min);
        System.out.println(Integer.MAX_VALUE);
    }
}