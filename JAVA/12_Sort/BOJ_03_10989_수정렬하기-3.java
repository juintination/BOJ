import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        int[] cnt = new int[10001];
        for (int i = 0; i < n; i++) {
            cnt[Integer.parseInt(br.readLine())]++;
        }
        int sum = 0;
        for (int i = 1; i <= 10000; i++) {
            bw.write(String.valueOf(i + "\n").repeat(cnt[i]));
            if (cnt[i] != 0) {
                for (int j = 0; j < cnt[i]; j++) {
                    sum++;
                }
            }
            if (sum == n) break;
        }
        bw.flush();
        bw.close();
    }
}