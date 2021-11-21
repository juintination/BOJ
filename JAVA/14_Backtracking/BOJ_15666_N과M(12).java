import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Arrays;

public class Main {

    static int n, m;
    static int[] arr, num;
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
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            if (tmp != num[i]) {
                if (dpth > 0 && arr[dpth - 1] > num[i]) continue;
                visited[i] = !visited[i];
                tmp = arr[dpth] = num[i];
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
        num = new int[n];
        arr = new int[m];
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; i++) {
            num[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(num);
        sb = new StringBuilder();
        dfs(0);
        System.out.print(sb);
    }
}