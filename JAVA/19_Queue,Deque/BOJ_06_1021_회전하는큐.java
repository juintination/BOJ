import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) throws IOException {
        LinkedList<Integer> deque = new LinkedList<Integer>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] arr = new int[m];
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < m; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        for (int i = 1; i <= n; i++) {
            deque.offer(i);
        }
        int move = 0;
        for (int i = 0; i < m; i++) {
            int rightcnt = 0, leftcnt = 0;
            int tmp = deque.peekFirst();
            for (int j = 0; j < deque.size(); j++) {
                if (arr[i] == deque.peekFirst()) break;
                deque.offerLast(deque.pollFirst());
                rightcnt++;
            }
            leftcnt = deque.size() - rightcnt;
            while (true) {
                if (deque.peekFirst() == tmp) break;
                deque.offerLast(deque.pollFirst());
            }
            if (rightcnt > leftcnt) {
                for (int j = 0; j < leftcnt; j++) {
                    int data = deque.pollLast();
                    deque.addFirst(data);
                    move++;
                }
            } else {
                for (int j = 0; j < rightcnt; j++) {
                    int data = deque.pollFirst();
                    deque.addLast(data);
                    move++;
                }
            }
            deque.pollFirst();
        }
        System.out.println(move);
    }
}