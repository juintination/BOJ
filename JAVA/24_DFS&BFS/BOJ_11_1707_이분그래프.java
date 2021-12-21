import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

    static int v, e;
    static boolean tst;
    static boolean[] visited, checked;
    static ArrayList<Integer>[] list;
    static Queue<Integer> queue;
    static StringBuilder sb;

    public static void bfs(int idx) {
        queue.offer(idx);
        checked[idx] = true;
        while (!queue.isEmpty()) {
            int tmp = queue.poll();
            visited[tmp] = true;
            if (list[tmp] != null) {
                for (int i : list[tmp]) {
                    if (!visited[i]) {
                        checked[i] = !checked[tmp];
                        queue.offer(i);
                    } else if (checked[tmp] == checked[i]) {
                        sb.append("NO\n");
                        tst = false;
                        return;
                    }
                }
            }
        }
    }

    @SuppressWarnings("unchecked")
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int k = Integer.parseInt(br.readLine());
        sb = new StringBuilder();
        while (k-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            v = Integer.parseInt(st.nextToken());
            e = Integer.parseInt(st.nextToken());
            visited = new boolean[v + 1];
            checked = new boolean[v + 1];
            list = new ArrayList[v + 1];
            for (int i = 1; i <= v; i++) {
                list[i] = new ArrayList<Integer>();
            }
            for (int i = 0; i < e; i++) {
                st = new StringTokenizer(br.readLine(), " ");
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                list[x].add(y);
                list[y].add(x);
            }
            tst = true;
            queue = new LinkedList<>();
            for (int i = 1; i <= v; i++) {
                if (!tst) break;
                if (!visited[i]) {
                    bfs(i);
                }
            }
            if (tst) sb.append("YES\n");
        }
        System.out.print(sb);
    }
}