import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    static String s, t;

    public static void dfs(String t) {
        if (t.length() == s.length()) {
            if (t.equals(s)) {
                System.out.println(1);
                System.exit(0);
            }
        } else if (t.length() == 0) return;
        if (t.charAt(0) == 'B') {
            StringBuilder sb = new StringBuilder();
            sb.append(t);
            sb.deleteCharAt(0);
            sb.reverse();
            dfs(sb.toString());
        }
        if (t.charAt(t.length() - 1) == 'A') {
            StringBuilder sb = new StringBuilder();
            sb.append(t);
            sb.deleteCharAt(t.length() - 1);
            dfs(sb.toString());
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        s = br.readLine();
        t = br.readLine();
        dfs(t);
        System.out.println(0);
    }
}