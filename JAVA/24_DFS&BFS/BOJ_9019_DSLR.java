import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;
import java.util.Arrays;
import java.util.StringTokenizer;

class register {
    int num;
    String str;

    public register(int num, String str) {
        this.num = num;
        this.str = str;
    }
}

public class Main {

    static int a, b;
    static boolean[] visited;
    static StringBuilder sb;

    public static void bfs(int a) {
        Queue<register> queue = new LinkedList<>();
        queue.offer(new register(a, ""));
        visited[a] = true;
        while (!queue.isEmpty()) {
            register p = queue.poll();
            int d = (2 * p.num) % 10000;
            if (!visited[d]) {
                if (d == b) {
                    sb.append(p.str + "D").append("\n");
                    return;
                }
                visited[d] = true;
                queue.offer(new register(d, p.str + "D"));
            }
            int s = (p.num == 0) ? 9999 : p.num - 1;
            if (!visited[s]) {
                if (s == b) {
                    sb.append(p.str + "S").append("\n");
                    return;
                }
                visited[s] = true;
                queue.offer(new register(s, p.str + "S"));
            }
            int l = (p.num % 1000) * 10 + p.num / 1000;
            if (!visited[l]) {
                if (l == b) {
                    sb.append(p.str + "L").append("\n");
                    return;
                }
                visited[l] = true;
                queue.offer(new register(l, p.str + "L"));
            }
            int r = (p.num % 10) * 1000 + p.num / 10;
            if (!visited[r]) {
                if (r == b) {
                    sb.append(p.str + "R").append("\n");
                    return;
                }
                visited[r] = true;
                queue.offer(new register(r, p.str + "R"));
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        visited = new boolean[10000];
        sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            Arrays.fill(visited, false);
            bfs(a);
        }
        System.out.print(sb);
    }
}