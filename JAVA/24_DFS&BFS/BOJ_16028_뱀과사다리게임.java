import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

    static int n, m, result;
    static int[] arr, cnt;
    static boolean[] visited;

    public static void bfs() {
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(1);
        visited[1] = true;
        while (!queue.isEmpty()) {
            int tmp = queue.poll();
            if (tmp == 100) {
                result = cnt[100];
                return;
            }
            for (int i = 6; i > 0; i--) {
                int e = tmp + i;
                if (e <= 100 && !visited[e]) {
                    if (arr[e] != 0) {
                        if (!visited[arr[e]]) {
                            queue.offer(arr[e]);
                            visited[arr[e]] = true;
                            cnt[arr[e]] = cnt[tmp] + 1;
                        }
                    } else {
                        queue.offer(e);
                        visited[e] = true;
                        cnt[e] = cnt[tmp] + 1;
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[101];
        cnt = new int[101];
        visited = new boolean[101];
        for (int i = 0; i < n + m; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            arr[x] = y;
        }
        bfs();
        System.out.println(result);
    }
}