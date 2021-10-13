import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        Stack<Integer> stack = new Stack<Integer>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int sum = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '(') {
                stack.push(1);
            } else {
                if (!stack.empty() && str.charAt(i - 1) == '(') {
                    stack.pop();
                    sum += stack.size();
                } else {
                    stack.pop();
                    sum++;
                }
            }
        }
        System.out.println(sum);
    }
}