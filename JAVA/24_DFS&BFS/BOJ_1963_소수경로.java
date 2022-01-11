import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;
import java.util.StringTokenizer;

class point {
    int x, cnt;

    public point(int x, int cnt) {
        this.x = x;
        this.cnt = cnt;
    }
}

public class Main {

    static int start, goal;
    static boolean[] sieved, visited;
    static StringBuilder sb = new StringBuilder();

    public static void eratosthenes() {
        sieved = new boolean[10000];
        sieved[1] = true;
        for (int i = 2; i < Math.sqrt(10000); i++) {
            if (sieved[i]) continue;
            for (int j = i * i; j < 10000; j += i) {
                sieved[j] = true;
            }
        }
    }

    public static void bfs() {
        Queue<point> queue = new LinkedList<>();
        queue.offer(new point(start, 0));
        visited[start] = true;
        while (!queue.isEmpty()) {
            point p = queue.poll();
            if (p.x == goal) {
                sb.append(p.cnt).append("\n");
                return;
            }
            int tmp = p.x;
            int[] digit = new int[4];
            int[] dx = { 1000, 100, 10, 1 };
            for (int i = 0; i < 4; i++) {
                digit[i] = tmp / dx[i];
                tmp %= dx[i];
            }
            for (int i = 0; i < 4; i++) {
                tmp = p.x - digit[i] * dx[i];
                for (int j = 0; j < 10; j++) {
                    if (i == 0 && j == 0) continue;
                    int nx = tmp + dx[i] * j;
                    if (!sieved[nx] && !visited[nx]) {
                        queue.offer(new point(nx, p.cnt + 1));
                        visited[nx] = true;
                    }
                }
            }
        }
        sb.append("Impossible\n");
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        eratosthenes();
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            start = Integer.parseInt(st.nextToken());
            goal = Integer.parseInt(st.nextToken());
            visited = new boolean[10000];
            bfs();
        }
        System.out.print(sb);
    }
}