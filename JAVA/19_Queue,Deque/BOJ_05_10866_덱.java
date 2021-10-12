import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.ArrayDeque;

public class Main {
    public static void main(String[] args) throws IOException {
        ArrayDeque<Integer> deque = new ArrayDeque<Integer>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            String str = st.nextToken();
            if (str.contains("push_front")) {
                deque.addFirst(Integer.parseInt(st.nextToken()));
            } else if (str.contains("push_back")) {
                deque.addLast(Integer.parseInt(st.nextToken()));
            } else if (str.contains("pop_front")) {
                if (deque.isEmpty()) {
                    sb.append(-1).append('\n');
                } else {
                    sb.append(deque.pollFirst()).append('\n');
                }
            } else if (str.contains("pop_back")) {
                if (deque.isEmpty()) {
                    sb.append(-1).append('\n');
                } else {
                    sb.append(deque.pollLast()).append('\n');
                }
            } else if (str.contains("size")) sb.append(deque.size()).append('\n');
            else if (str.contains("empty")) {
                if (deque.isEmpty()) {
                    sb.append(1).append('\n');
                } else {
                    sb.append(0).append('\n');
                }
            } else if (str.contains("front")) {
                if (deque.isEmpty()) {
                    sb.append(-1).append('\n');
                } else {
                    sb.append(deque.peekFirst()).append('\n');
                }
            } else if (str.contains("back")) {
                if (deque.isEmpty()) {
                    sb.append(-1).append('\n');
                } else {
                    sb.append(deque.peekLast()).append('\n');
                }
            }
        }
        System.out.println(sb);
    }
}