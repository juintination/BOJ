import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int k;
    static int[] arr;
    static char[] inequal;
    static boolean[] visited;
    static boolean first = true;
    static String max, min;

    public static void dfs(int dpth) {
        if (dpth == k + 1) {
            StringBuilder sb2 = new StringBuilder();
            for (int i = 0; i <= k; i++) {
                sb2.append(arr[i]);
            }
            if (first) {
                min = sb2.toString();
                first = !first;
            } else {
                max = sb2.toString();
            }
            return;
        }
        for (int i = 0; i < 10; i++) {
            if (!visited[i]) {
                if (inequal[dpth] == '>' && arr[dpth - 1] > i) {
                    visited[i] = true;
                    arr[dpth] = i;
                    dfs(dpth + 1);
                    visited[i] = false;
                } else if (inequal[dpth] == '<' && arr[dpth - 1] < i) {
                    visited[i] = true;
                    arr[dpth] = i;
                    dfs(dpth + 1);
                    visited[i] = false;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        k = Integer.parseInt(br.readLine());
        arr = new int[k + 1];
        inequal = new char[k + 1];
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 1; i <= k; i++) {
            inequal[i] = st.nextToken().charAt(0);
        }
        visited = new boolean[10];
        for (int i = 0; i < 10; i++) {
            visited[i] = true;
            arr[0] = i;
            dfs(1);
            visited[i] = false;
        }
        StringBuilder sb = new StringBuilder();
        sb.append(max).append("\n").append(min);
        System.out.print(sb);
    }
}