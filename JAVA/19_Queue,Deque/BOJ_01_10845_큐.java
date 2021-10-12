import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Deque;
import java.util.ArrayDeque;

public class Main {
    public static void main(String[] args) throws IOException {
        Deque<Integer> q = new ArrayDeque<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            String str = st.nextToken();
            if (str.contains("push")) {
                q.offer(Integer.parseInt(st.nextToken()));
            } else if (str.contains("pop")) {
                Integer p = q.poll();
                if (p == null) {
                    sb.append(-1).append('\n');
                } else {
                    sb.append(p).append('\n');
                }
            } else if (str.contains("size"))
                sb.append(q.size()).append('\n');
            else if (str.contains("empty")) {
                if (q.isEmpty()) {
                    sb.append(1).append('\n');
                } else {
                    sb.append(0).append('\n');
                }
            } else if (str.contains("front")) {
                Integer f = q.peek();
                if (f == null) {
                    sb.append(-1).append('\n');
                } else {
                    sb.append(f).append('\n');
                }
            } else if (str.contains("back")) {
                Integer r = q.peekLast();
                if (r == null) {
                    sb.append(-1).append('\n');
                } else {
                    sb.append(r).append('\n');
                }
            }
        }
        System.out.println(sb);
    }
}