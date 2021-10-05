import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        int j = 0, max = 0;
        int num[] = new int[9];
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < 9; i++) {
            num[i] = Integer.parseInt(st.nextToken());
            if (num[i] > max) {
                max = num[i];
                j = i;
            }
        }
        System.out.println(max + "\n" + (j + 1));
    }
}