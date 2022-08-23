import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Arrays;
import java.util.Queue;
import java.util.LinkedList;
import java.util.Stack;

public class Main {

    static int[] parent = new int[10000];
    static char[] str = new char[10001];
    static boolean[] visited = new boolean[10000];
    static StringBuilder sb = new StringBuilder();

    public static void bfs(int a, int b) {
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(a);
        visited[a] = true;
        while (!queue.isEmpty()) {
            int p = queue.poll();
            int d = (2 * p) % 10000;
            if (!visited[d]) {
                str[d] = 'D';
                parent[d] = p;
                if (d == b) break;
                visited[d] = true;
                queue.offer(d);
            }
            int s = (p == 0) ? 9999 : p - 1;
            if (!visited[s]) {
                str[s] = 'S';
                parent[s] = p;
                if (s == b) break;
                visited[s] = true;
                queue.offer(s);
            }
            int l = (p % 1000) * 10 + p / 1000;
            if (!visited[l]) {
                str[l] = 'L';
                parent[l] = p;
                if (l == b) break;
                visited[l] = true;
                queue.offer(l);
            }
            int r = (p % 10) * 1000 + p / 10;
            if (!visited[r]) {
                str[r] = 'R';
                parent[r] = p;
                if (r == b) break;
                visited[r] = true;
                queue.offer(r);
            }
        }
        Stack<Character> stack = new Stack<>();
        while (b != a) {
            stack.push(str[b]);
            b = parent[b];
        }
        while (!stack.empty()) {
            sb.append(stack.pop());
        }
        sb.append("\n");
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            Arrays.fill(visited, false);
            bfs(a, b);
        }
        System.out.print(sb);
    }
}