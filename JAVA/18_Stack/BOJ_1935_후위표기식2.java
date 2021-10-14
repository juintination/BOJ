import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        Stack<Double> stack = new Stack<Double>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        double[] value = new double[n];
        String str = br.readLine();
        for (int i = 0; i < n; i++) {
            value[i] = Double.parseDouble(br.readLine());
        }
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) >= 'A' && str.charAt(i) <= 'Z') {
                stack.push(value[str.charAt(i) - 65]);
            } else if (str.charAt(i) == '+') {
                double b = stack.pop();
                double a = stack.pop();
                stack.push(a + b);
            } else if (str.charAt(i) == '-') {
                double b = stack.pop();
                double a = stack.pop();
                stack.push(a - b);
            } else if (str.charAt(i) == '*') {
                double b = stack.pop();
                double a = stack.pop();
                stack.push(a * b);
            } else if (str.charAt(i) == '/') {
                double b = stack.pop();
                double a = stack.pop();
                stack.push(a / b);
            }
        }
        System.out.print(String.format("%.2f", stack.pop()));
    }
}