import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while (true) {
            int tst = 0;
            String str = br.readLine();
            if (str.equals(".")) break;
            Stack<Character> stack = new Stack<>();
            for (int i = 0; i < str.length(); i++) {
                if (str.charAt(i) == '(' || str.charAt(i) == '[') {
                    stack.push(str.charAt(i));
                } else if (str.charAt(i) == ')') {
                    if (stack.empty() || stack.peek() != '(') {
                        sb.append("no\n");
                        tst++;
                        break;
                    } else stack.pop();
                }
                else if (str.charAt(i) == ']') {
                    if (stack.empty() || stack.peek() != '[') {
                        sb.append("no\n");
                        tst++;
                        break;
                    } else stack.pop();
                }
            }
            if (tst == 0) {
                if (stack.empty()) sb.append("yes\n");
                else sb.append("no\n");
            }
        }
        System.out.println(sb);
    }
}