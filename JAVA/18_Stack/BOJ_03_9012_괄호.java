import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            Stack<Integer> stack = new Stack<>();
            String str = br.readLine();
            int sum = 0;
            for (int j = 0; j < str.length(); j++) {
                if (str.charAt(j) == '(') {
                    stack.push(1);
                    sum++;
                } else {
                    if (stack.empty()) {
                        sb.append("NO\n");
                        sum--;
                        break;
                    } else sum -= stack.pop();
                }
            }
            if (sum == 0) sb.append("YES\n");
            else if (sum > 0) sb.append("NO\n");
        }
        System.out.println(sb);
    }
}