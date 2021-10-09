import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        Stack<Integer> stack = new Stack<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        int tmp = 0, tst = 0;
        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(br.readLine());
            if (num > tmp) {
                for (int j = tmp + 1; j <= num; j++) {
                    stack.push(j);
                    sb.append("+\n");
                }
                tmp = num;
            }
            else if (stack.peek() != num) {
                System.out.println("NO");
                tst++;
                return;
            }
            stack.pop();
            sb.append("-\n");
        }
        if (tst == 0) System.out.println(sb);
    }
}