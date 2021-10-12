import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            LinkedList<Integer> deque = new LinkedList<Integer>();
            boolean swap = true, tst = true;
            String p = br.readLine();
            int n = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine(), "[],");
            for (int i = 0; i < n; i++) {
                deque.addLast(Integer.parseInt(st.nextToken()));
            }
            for (int i = 0; i < p.length(); i++) {
                if (p.charAt(i) == 'R') {
                    swap = !swap;
                } else if (p.charAt(i) == 'D') {
                    if (deque.isEmpty()) {
                        sb.append("error\n");
                        tst = false;
                        break;
                    } else if (swap == true) {
                        deque.pollFirst();
                    } else deque.pollLast();
                }
            }
            if (tst == true) {
                sb.append("[");
                while (!deque.isEmpty()) {
                    if (swap == true) sb.append(deque.pollFirst());
                    else sb.append(deque.pollLast());
                    if (deque.size() > 0) sb.append(",");
                }
                sb.append("]\n");
            }
        }
        System.out.println(sb);
    }
}