import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, k, max = 0;
    static int[] words;

    public static void dfs(int dpth, int idx, int mask) {
        if (dpth == k - 5) {
            int cnt = 0;
            for (int word : words) {
                int tmp = (word | mask);
                if (tmp == mask) {
                    cnt++;
                }
            }
            max = Math.max(max, cnt);
            return;
        }
        for (int i = idx; i < 26; i++) {
            if ((mask & 1 << i) == 0) {
                dfs(dpth + 1, i + 1, mask | 1 << i);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        int mask = 0;
        String init = "antic";
        for (int i = 0; i < 5; i++) {
            mask |= 1 << init.charAt(i) - 'a';
        }
        words = new int[n];
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            int bit = mask;
            for (int j = 4; j < str.length() - 4; j++) {
                bit |= 1 << str.charAt(j) - 'a';
            }
            words[i] = bit;
        }
        if (k < 5) {
            System.out.println(0);
            return;
        } else if (k == 26) {
            System.out.println(n);
            return;
        }
        dfs(0, 0, mask);
        System.out.println(max);
    }
}