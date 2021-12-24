import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Queue;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

    static int n, cnt = 0;
    static int[] arr, order;
    static boolean[] visited;
    static ArrayList<Integer>[] list;

    public static void bfs(int idx) {
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(idx);
        while (!queue.isEmpty()) {
            int tmp = queue.poll();
            if (tmp != arr[cnt++]) {
                System.out.println(0);
                System.exit(0);
            }
            visited[tmp] = true;
            if (list[tmp] != null) {
                for (int e : list[tmp]) {
                    if (!visited[e]) {
                        queue.offer(e);
                        visited[e] = true;
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
        list = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            list[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < n - 1; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            list[x].add(y);
            list[y].add(x);
        }
        arr = new int[n];
        order = new int[n + 1];
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; i++) {
            int tmp = Integer.parseInt(st.nextToken());
            arr[i] = tmp;
            order[tmp] = i;
        }
        for (int i = 1; i <= n; i++) {
            if (list[i] != null) {
                Collections.sort(list[i], new Comparator<Integer>() {
                    @Override
                    public int compare(Integer o1, Integer o2) {
                        return order[o1] - order[o2];
                    }
                });
            }
        }
        bfs(1);
        System.out.println(1);
    }
}