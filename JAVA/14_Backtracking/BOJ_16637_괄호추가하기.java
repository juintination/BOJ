import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {

    static int max = Integer.MIN_VALUE;
    static ArrayList<Integer> number;
    static ArrayList<Character> operator;

    public static int cal(int n1, char op, int n2) {
        if (op == '+') return n1 + n2;
        else if (op == '-') return n1 - n2;
        else return n1 * n2;
    }

    public static void dfs(int dpth, int sum) {
        if (dpth == operator.size()) {
            max = Math.max(max, sum);
            return;
        }
        int tmp1 = cal(sum, operator.get(dpth), number.get(dpth + 1));
        dfs(dpth + 1, tmp1);
        if (dpth + 1 < operator.size()) {
            int tmp2 = cal(number.get(dpth + 1), operator.get(dpth + 1), number.get(dpth + 2));
            tmp2 = cal(sum, operator.get(dpth), tmp2);
            dfs(dpth + 2, tmp2);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String str = br.readLine();
        number = new ArrayList<>();
        operator = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            char c = str.charAt(i);
            if (c == '+' || c == '-' || c == '*') {
                operator.add(c);
            } else {
                number.add(c - '0');
            }
        }
        dfs(0, number.get(0));
        System.out.println(max);
    }
}