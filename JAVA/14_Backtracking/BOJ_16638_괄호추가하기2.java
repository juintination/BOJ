import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Stack;

public class Main {

	static int max = Integer.MIN_VALUE;
	static ArrayList<Integer> number;
	static ArrayList<Character> operator;

	public static int prec(char op) {
		if (op == '(') return -1;
		else if (op == '+' || op == '-') return 0;
		else return 1;
	}

	public static int cal(int n1, char op, int n2) {
		if (op == '+') return n1 + n2;
		else if (op == '-') return n1 - n2;
		else return n1 * n2;
	}

	public static int getResult(String str) {
		Stack<Integer> stackNum = new Stack<>();
		Stack<Character> stackOp = new Stack<>();
		int len = str.length();
		for (int i = 0; i < len; i++) {
			char c = str.charAt(i);
			if ('0' <= c && c <= '9') {
				stackNum.push(c - '0');
			} else if (c == '(') {
				stackOp.push(c);
			} else if (c == ')') {
				while (stackOp.peek() != '(') {
					int n2 = stackNum.pop(), n1 = stackNum.pop();
					stackNum.push(cal(n1, stackOp.pop(), n2));
				}
				stackOp.pop();
			} else {
				while (!stackOp.empty() && prec(stackOp.peek()) >= prec(c)) {
					int n2 = stackNum.pop(), n1 = stackNum.pop();
					stackNum.push(cal(n1, stackOp.pop(), n2));
				}
				stackOp.push(c);
			}
		}
		while (!stackOp.empty()) {
			int n2 = stackNum.pop(), n1 = stackNum.pop();
			stackNum.push(cal(n1, stackOp.pop(), n2));
		}
		return stackNum.pop();
	}

	public static void dfs(int dpth, String str) {
		if (dpth == operator.size()) {
			if (str.charAt(str.length() - 1) != ')') {
				StringBuilder sb = new StringBuilder(str);
				sb.append(number.get(dpth));
				str = sb.toString();
			}
			max = Math.max(max, getResult(str));
			return;
		}
		StringBuilder sb1 = new StringBuilder(str);
		sb1.append(number.get(dpth)).append(operator.get(dpth));
		dfs(dpth + 1, sb1.toString());
		StringBuilder sb2 = new StringBuilder(str);
		sb2.append('(').append(number.get(dpth)).append(operator.get(dpth)).append(number.get(dpth + 1)).append(')');
		if (dpth + 1 < operator.size()) {
			sb2.append(operator.get(dpth + 1));
			dfs(dpth + 2, sb2.toString());
		} else dfs(dpth + 1, sb2.toString());
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		String str = br.readLine();
		if (n == 1) {
			System.out.println(str);
			System.exit(0);
		}
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
		dfs(0, "");
		System.out.println(max);
	}
}