import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, max;
    static int[] arr, num;
    static boolean[] visited;

    public static void dfs(int dpth) {
        if (dpth == n) {
            int sum = 0;
            for (int i = 1; i < n; i++) {
                sum += Math.abs(arr[i] - arr[i - 1]);
            }
            max = Math.max(max, sum);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                arr[dpth] = num[i];
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
        num = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; i++) {
            num[i] = Integer.parseInt(st.nextToken());
        }
        max = 0;
        dfs(0);
        System.out.println(max);
    }
}