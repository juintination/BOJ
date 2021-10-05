import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int min = 0;
        int m;
        for (int i = 0; i < n; i++) {
            String str = Integer.toString(i);
            m = i;
            for (int j = 0; j < str.length(); j++) {
                m += str.charAt(j) - '0';
            }
            if (m == n) {
                min = i;
                break;
            }
        }
        bw.write(min + "");
        bw.flush();
        bw.close();
    }
}