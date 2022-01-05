import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;
import java.util.StringTokenizer;

class stone {
    int a, b, c;

    public stone(int a, int b, int c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
}

public class Main {

    static int a, b, c;
    static boolean[][] visited;

    public static void bfs(int a, int b, int c) {
        Queue<stone> queue = new LinkedList<>();
        queue.offer(new stone(a, b, c));
        while (!queue.isEmpty()) {
            stone s = queue.poll();
            a = s.a;
            b = s.b;
            c = s.c;
            if (a == b && b == c) {
                System.out.println(1);
                System.exit(0);
            }
            if (a != b) {
                int na = a > b ? a - b : a * 2;
                int nb = a > b ? b * 2 : b - a;
                if (na <= 1000 && nb <= 1000 && !visited[na][nb]) {
                    queue.offer(new stone(na, nb, c));
                    visited[na][nb] = true;
                    visited[nb][na] = true;
                }
            }
            if (b != c) {
                int nb = b > c ? b - c : b * 2;
                int nc = b > c ? c * 2 : c - b;
                if (nb <= 1000 && nc <= 1000 && !visited[nb][nc]) {
                    queue.offer(new stone(a, nb, nc));
                    visited[nb][nc] = true;
                    visited[nc][nb] = true;
                }
            }
            if (c != a) {
                int nc = c > a ? c - a : c * 2;
                int na = c > a ? a * 2 : a - c;
                if (na <= 1000 && nc <= 1000 && !visited[na][nc]) {
                    queue.offer(new stone(na, b, nc));
                    visited[na][nc] = true;
                    visited[nc][na] = true;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        visited = new boolean[1001][1001];
        bfs(a, b, c);
        System.out.println(0);
    }
}