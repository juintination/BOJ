import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int E = Integer.parseInt(st.nextToken());
        int S = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[] esm = new int[] { 1, 1, 1 };
        int cnt = 1;
        while (true) {
            if (E == esm[0] && S == esm[1] && M == esm[2]) {
                System.out.println(cnt);
                break;
            }
            for (int i = 0; i < 3; i++) {
                esm[i]++;
            }
            cnt++;
            if (esm[0] == 16) esm[0] = 1;
            if (esm[1] == 29) esm[1] = 1;
            if (esm[2] == 20) esm[2] = 1;
            /*
             * esm[0] %= 15; esm[1] %= 28; esm[2] %= 19;
             * 비슷한 의미이지만 예제 4에서 시간이 너무 오래 걸린다
             */
        }
    }
}