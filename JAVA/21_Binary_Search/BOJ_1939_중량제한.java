import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;
import java.util.LinkedList;
import java.util.StringTokenizer;

class point {
    int x, cost;

    public point(int x, int cost) {
        this.x = x;
        this.cost = cost;
    }
}

public class Main {

    static int n, m, start, end;
    static boolean[] visited;
    static ArrayList<point>[] list;

    public static boolean bfs(int mid) {
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(start);
        visited[start] = true;
        while (!queue.isEmpty()) {
            int tmp = queue.poll();
            if (tmp == end) {
                return true;
            }
            if (list[tmp] != null) {
                for (point p : list[tmp]) {
                    if (!visited[p.x] && mid <= p.cost) {
                        queue.offer(p.x);
                        visited[p.x] = true;
                    }
                }
            }
        }
        return false;
    }

    @SuppressWarnings("unchecked")
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        list = new ArrayList[n + 1];
        visited = new boolean[n + 1];
        for (int i = 1; i <= n; i++) {
            list[i] = new ArrayList<point>();
        }
        int max = 0, min = Integer.MAX_VALUE;
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine(), " ");
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            max = Math.max(max, c);
            min = Math.min(min, c);
            list[a].add(new point(b, c));
            list[b].add(new point(a, c));
        }
        st = new StringTokenizer(br.readLine());
        start = Integer.parseInt(st.nextToken());
        end = Integer.parseInt(st.nextToken());
        int result = 0;
        while (min <= max) {
            int mid = (max + min) / 2;
            Arrays.fill(visited, false);
            if (bfs(mid)) {
                result = mid;
                min = mid + 1;
            } else {
                max = mid - 1;
            }
        }
        System.out.println(result);
    }
}