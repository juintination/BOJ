import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        String t = br.readLine();
        StringBuilder sb = new StringBuilder();
        sb.append(t);
        while (sb.length() > s.length()) {
            char c = sb.charAt(sb.length() - 1);
            sb.deleteCharAt(sb.length() - 1);
            if (c == 'B') {
                sb.reverse();
            }
        }
        if (sb.toString().equals(s)) {
            System.out.println(1);
        } else {
            System.out.println(0);
        }
    }
}