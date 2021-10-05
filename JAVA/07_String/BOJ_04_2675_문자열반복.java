import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int c = Integer.parseInt(br.readLine());
        String str[] = new String[c];
        int n[] = new int[c];
        for (int k = 0; k < c; k++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            n[k] = Integer.parseInt(st.nextToken());
            str[k] = st.nextToken();
        }
        StringBuilder sb = new StringBuilder();
        for (int k = 0; k < c; k++) {
            for (int i = 0; i < str[k].length(); i++) {
                for (int j = 0; j < n[k]; j++) {
                    sb.append(str[k].charAt(i));
                }
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
}