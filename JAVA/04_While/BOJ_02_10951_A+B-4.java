import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str;
        StringBuilder sb = new StringBuilder();
        while ((str = br.readLine()) != null) {
            int x = str.charAt(0) - '0';
            int y = str.charAt(2) - '0';
            sb.append(x + y).append("\n");
        }
        System.out.print(sb);
    }
}