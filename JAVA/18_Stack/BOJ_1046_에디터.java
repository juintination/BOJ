import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        Stack<Character> lstack = new Stack<>();
        Stack<Character> rstack = new Stack<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        for (int i = 0; i < str.length(); i++) {
            lstack.push(str.charAt(i));
        }
        int m = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < m; i++) {
            String commander = br.readLine();
            if (commander.charAt(0) == 'L') {
                if (!lstack.empty()) {
                    rstack.push(lstack.pop());
                }
            } else if (commander.charAt(0) == 'D') {
                if (!rstack.empty()) {
                    lstack.push(rstack.pop());
                }
            } else if (commander.charAt(0) == 'P') {
                lstack.push(commander.charAt(2));
            } else if (commander.charAt(0) == 'B') {
                if (!lstack.empty()) {
                    lstack.pop();
                }
            }
        }
        while (!lstack.empty()) {
            rstack.push(lstack.pop());
        }
        while (!rstack.empty()) {
            sb.append(rstack.pop());
        }
        System.out.println(sb);
    }
}