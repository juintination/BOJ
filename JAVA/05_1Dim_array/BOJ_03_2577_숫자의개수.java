import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n[] = new int[3];
        int result = 1;
        for (int i = 0; i < 3; i++) {
            n[i] = Integer.parseInt(br.readLine());
            result *= n[i];
        }
        StringBuilder sb = new StringBuilder();
        String str = Integer.toString(result);
        for (int i = 0; i < 10; i++) {
            int cnt = 0;
            for (int j = 0; j < str.length(); j++) {
                if (str.charAt(j) - '0' == i) cnt++;
            }
            sb.append(cnt).append("\n");
        }
        System.out.println(sb);
    }
}