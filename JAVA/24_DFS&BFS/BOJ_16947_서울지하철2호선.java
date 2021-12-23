import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

    static int n, start;
    static int[] cnt;
    static boolean[] visited, cycled;
    static ArrayList<Integer>[] list;

    public static boolean dfs(int idx, int parent) {
        visited[idx] = true;
        if (list[idx] != null) {
            for (int e : list[idx]) {
                if (!visited[e]) {
                    if (dfs(e, idx)) {
                        cycled[e] = true;
                        return true;
                    }
                } else if (e != parent && e == start) {
                    cycled[e] = true;
                    return true;
                }
            }
        }
        return false;
    }

    public static void bfs() {
        Queue<Integer> queue = new LinkedList<>();
        Arrays.fill(visited, false);
        for (int i = 1; i <= n; i++) {
            if (cycled[i]) {
                visited[i] = true;
                queue.offer(i);
            }
        }
        while (!queue.isEmpty()) {
            int tmp = queue.poll();
            visited[tmp] = true;
            if (list[tmp] != null) {
                for (int e : list[tmp]) {
                    if (!visited[e]) {
                        queue.offer(e);
                        visited[e] = true;
                        cnt[e] = cnt[tmp] + 1;
                    }
                }
            }
        }
    }

    @SuppressWarnings("unchecked")
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        visited = new boolean[n + 1];
        cycled = new boolean[n + 1];
        list = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            list[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            list[x].add(y);
            list[y].add(x);
        }
        for (int i = 1; i <= n; i++) {
            start = i;
            if (dfs(i, 0)) {
                break;
            } else {
                Arrays.fill(visited, false);
            }
        }
        cnt = new int[n + 1];
        bfs();
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= n; i++) {
            sb.append(cnt[i]).append(" ");
        }
        System.out.println(sb);
    }
}