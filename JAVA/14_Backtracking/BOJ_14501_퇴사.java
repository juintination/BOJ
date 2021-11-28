import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, max;
    static int[][] arr;

    public static void dfs(int dpth, int sum) {
        if (dpth == n) {
            max = Math.max(max, sum);
            return;
        }
        if (dpth + arr[dpth][0] <= n) {
            dfs(dpth + arr[dpth][0], sum + arr[dpth][1]);
        }
        dfs(dpth + 1, sum);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n][2];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
        }
        max = 0;
        dfs(0, 0);
        System.out.println(max);
    }
}