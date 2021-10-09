import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            Stack<Character> stack = new Stack<>();
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            while (st.countTokens() != 0) {
                String str = st.nextToken();
                for (int j = 0; j < str.length(); j++) {
                    stack.push(str.charAt(j));
                }
                while (!stack.empty()) {
                    sb.append(stack.pop());
                }
                sb.append(" ");
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
}