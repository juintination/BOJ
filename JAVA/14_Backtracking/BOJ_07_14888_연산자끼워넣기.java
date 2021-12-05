import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, max, min;
    static int[] arr, operator;

    public static void dfs(int dpth, int result) {
        if (dpth == n) {
            max = Math.max(max, result);
            min = Math.min(min, result);
            return;
        }
        for (int i = 0; i < 4; i++) {
            if (operator[i] > 0) {
                operator[i]--;
                if (i == 0) {
                    dfs(dpth + 1, result + arr[dpth]);
                } else if (i == 1) {
                    dfs(dpth + 1, result - arr[dpth]);
                } else if (i == 2) {
                    dfs(dpth + 1, result * arr[dpth]);
                } else {
                    dfs(dpth + 1, result / arr[dpth]);
                }
                operator[i]++;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n];
        operator = new int[4];
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < 4; i++) {
            operator[i] = Integer.parseInt(st.nextToken());
        }
        StringBuilder sb = new StringBuilder();
        max = Integer.MIN_VALUE;
        min = Integer.MAX_VALUE;
        dfs(1, arr[0]);
        sb.append(max).append("\n").append(min);
        System.out.print(sb);
    }
}