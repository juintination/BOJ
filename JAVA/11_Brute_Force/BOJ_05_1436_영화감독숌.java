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
        int cnt = 0, num = 666;
        while (true) {
            if (String.valueOf(num).contains("666")) {
                cnt++;
            }
            if (cnt == n) {
                break;
            }
            num++;
        }
        bw.write(num + "");
        bw.flush();
        bw.close();
    }
}