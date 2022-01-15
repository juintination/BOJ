import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < n; i++) {
            int coin = Integer.parseInt(br.readLine());
            if (coin > k) continue;
            stack.push(coin);
        }
        int cnt = 0;
        while (k > 0) {
            int tmp = stack.pop();
            cnt += (k / tmp);
            k %= tmp;
        }
        System.out.println(cnt);
    }
}