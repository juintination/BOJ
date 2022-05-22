import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] cnt = new int[n + 1];
        Arrays.fill(cnt, -2);
        boolean[][] friended = new boolean[n + 1][n + 1];
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine(), " ");
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            friended[x][y] = friended[y][x] = true;
            cnt[x]++;
            cnt[y]++;
        }
        int min = Integer.MAX_VALUE;
        for (int i = 1; i <= n - 2; i++) {
            for (int j = i + 1; j <= n - 1; j++) {
                if (friended[i][j]) {
                    for (int k = j + 1; k <= n; k++) {
                        if (friended[j][k] && friended[k][i]) {
                            int sum = cnt[i] + cnt[j] + cnt[k];
                            min = Math.min(min, sum);
                        }
                    }
                }
            }
        }
        if (min == Integer.MAX_VALUE) {
            System.out.println(-1);
        } else {
            System.out.println(min);
        }
    }
}