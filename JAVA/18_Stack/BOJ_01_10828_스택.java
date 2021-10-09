import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static int[] stack;
    public static int idx = -1;

    public static void push(int item) {
        stack[++idx] = item;
    }

    public static int pop() {
        if (idx < 0) {
            return -1;
        } else {
            return stack[idx--];
        }
    }

    public static int size() {
        return idx + 1;
    }

    public static int empty() {
        if (idx < 0) {
            return 1;
        } else {
            return 0;
        }
    }

    public static int top() {
        if (idx < 0) {
            return -1;
        } else {
            return stack[idx];
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        stack = new int[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            String str = st.nextToken();
            if (str.contains("push")) push(Integer.parseInt(st.nextToken()));
            else if (str.contains("pop")) sb.append(pop()).append("\n");
            else if (str.contains("top")) sb.append(top()).append("\n");
            else if (str.contains("empty")) sb.append(empty()).append("\n");
            else if (str.contains("size")) sb.append(size()).append("\n");
        }
        System.out.println(sb);
    }
}