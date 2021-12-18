import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    static int n, k;
    static int[] arr = new int[100001];
    static int[] parent = new int[100001];
    static StringBuilder sb = new StringBuilder();

    public static void bfs(int idx) {
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(idx);
        while (!queue.isEmpty()) {
            int x = queue.poll();
            if (x == k) break;
            int[] dx = { x - 1, x + 1, x * 2 };
            for (int nx : dx) {
                if (nx >= 0 && nx <= 100000 && arr[nx] == 0) {
                    queue.offer(nx);
                    arr[nx] = arr[x] + 1;
                    parent[nx] = x;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        bfs(n);
        sb.append(arr[k]).append("\n");
        Stack<Integer> stack = new Stack<>();
        int tmp = k;
        while (tmp != n) {
            stack.push(tmp);
            tmp = parent[tmp];
        }
        stack.push(tmp);
        while (!stack.isEmpty()) {
            sb.append(stack.pop()).append(" ");
        }
        System.out.println(sb);
    }
}