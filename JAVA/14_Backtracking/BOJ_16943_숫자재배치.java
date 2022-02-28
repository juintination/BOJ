import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static String a;
    static int b;
    static int[] arr;
    static boolean[] visited;

    public static void dfs(int dpth, int sum) {
        if (dpth == a.length()) {
            System.out.println(sum);
            System.exit(0);
        }
        for (int i = a.length() - 1; i >= 0; i--) {
            if (dpth == 0 && arr[i] == 0) continue;
            if (!visited[i]) {
                if (sum * 10 + arr[i] < b) {
                    visited[i] = true;
                    dfs(dpth + 1, sum * 10 + arr[i]);
                    visited[i] = false;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        a = st.nextToken();
        b = Integer.parseInt(st.nextToken());
        arr = new int[a.length()];
        visited = new boolean[a.length()];
        for (int i = 0; i < a.length(); i++) {
            arr[i] = a.charAt(i) - '0';
        }
        Arrays.sort(arr);
        dfs(0, 0);
        System.out.println(-1);
    }
}