import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Arrays;

public class Main {

    static int l, c;
    static char[] arr, password;
    static boolean[] visited;
    static StringBuilder sb;

    public static void dfs(int dpth) {
        if (dpth == l) {
            StringBuilder sb2 = new StringBuilder();
            int vowel = 0, consonant = 0;
            for (int i = 0; i < l; i++) {
                sb2.append(arr[i]);
                if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
                    vowel++;
                } else consonant++;
            }
            if (vowel > 0 && consonant >= 2) {
                sb.append(sb2).append("\n");
            }
            return;
        }
        for (int i = 0; i < c; i++) {
            if (!visited[i]) {
                if (dpth > 0 && arr[dpth - 1] > password[i]) continue;
                visited[i] = true;
                arr[dpth] = password[i];
                dfs(dpth + 1);
                visited[i] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        l = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        arr = new char[l];
        password = new char[c];
        visited = new boolean[c];
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < c; i++) {
            password[i] = st.nextToken().charAt(0);
        }
        Arrays.sort(password);
        sb = new StringBuilder();
        dfs(0);
        System.out.print(sb);
    }
}