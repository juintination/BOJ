import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int n, l, r, x, cnt = 0;
    static int[] arr;

    public static void dfs(int idx, int dpth, int min, int max, int sum) {
        if (dpth >= 2) {
            if (l <= sum && sum <= r && max - min >= x) {
                cnt++;
            }
        }
        for (int i = idx; i < n; i++) {
            dfs(i + 1, dpth + 1, Math.min(min, arr[i]), Math.max(max, arr[i]), sum + arr[i]);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        l = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());
        arr = new int[n];
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);
        dfs(0, 0, Integer.MAX_VALUE, 0, 0);
        System.out.println(cnt);
    }
}