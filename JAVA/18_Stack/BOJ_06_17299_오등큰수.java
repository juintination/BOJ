import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        Stack<Integer> stack = new Stack<Integer>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] num = new int[n];
        int[] cnt = new int[1000001];
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; i++) {
            num[i] = Integer.parseInt(st.nextToken());
            cnt[num[i]]++;
        }
        for (int i = 0; i < n; i++) {
            while (!stack.empty() && cnt[num[stack.peek()]] < cnt[num[i]]) {
                num[stack.pop()] = num[i];
            }
            stack.push(i);
        }
        while (stack.size() > 0) {
            num[stack.pop()] = -1;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            sb.append(num[i]).append(" ");
        }
        System.out.println(sb);
    }
}