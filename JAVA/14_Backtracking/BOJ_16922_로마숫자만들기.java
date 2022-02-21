import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;

public class Main {

    static int n;
    static int[] IVXL = { 1, 5, 10, 50 };
    static HashSet<Integer> set = new HashSet<>();

    public static void dfs(int dpth, int idx, int sum) {
        if (dpth == n) {
            if (!set.contains(sum)) {
                set.add(sum);
            }
            return;
        }
        for (int i = idx; i < 4; i++) {
            dfs(dpth + 1, i, sum + IVXL[i]);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        dfs(0, 0, 0);
        System.out.println(set.size());
    }
}