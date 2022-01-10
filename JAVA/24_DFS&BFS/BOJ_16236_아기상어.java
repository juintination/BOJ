import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

class point {
    int x, y, cnt;

    public point(int x, int y, int cnt) {
        this.x = x;
        this.y = y;
        this.cnt = cnt;
    }
}

public class Main {

    static int n, x, y, result = 0;
    static int[][] arr;

    public static point bfs(point e, int level) {
        ArrayList<point> list = new ArrayList<>();
        Queue<point> queue = new LinkedList<>();
        boolean[][] visited = new boolean[n][n];
        queue.offer(new point(e.x, e.y, 0));
        visited[e.x][e.y] = true;
        int[] dx = { -1, 0, 1, 0 };
        int[] dy = { 0, -1, 0, 1 };
        while (!queue.isEmpty()) {
            point p = queue.poll();
            if (arr[p.x][p.y] != 0 && level > arr[p.x][p.y]) {
                list.add(p);
                continue;
            }
            for (int i = 0; i < 4; i++) {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && level >= arr[nx][ny]) {
                    queue.offer(new point(nx, ny, p.cnt + 1));
                    visited[nx][ny] = true;
                }
            }
        }
        point next = null;
        Collections.sort(list, new Comparator<point>() {
            @Override
            public int compare(point o1, point o2) {
                if (o1.x == o2.x) {
                    return o1.y - o2.y;
                }
                return o1.x - o2.x;
            }
        });
        int min = Integer.MAX_VALUE;
        for (point p : list) {
            if (p.cnt < min) {
                next = p;
                min = p.cnt;
            }
        }
        return next;
    }

    public static void babyshark() {
        Queue<point> queue = new LinkedList<>();
        queue.offer(new point(x, y, 0));
        int eat = 0, level = 2;
        while (!queue.isEmpty()) {
            point p = bfs(queue.poll(), level);
            if (p == null) {
                return;
            } else {
                queue.offer(p);
                arr[p.x][p.y] = 0;
                result += p.cnt;
                eat++;
                if (eat == level) {
                    level++;
                    eat = 0;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n][n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (arr[i][j] == 9) {
                    arr[i][j] = 0;
                    x = i;
                    y = j;
                }
            }
        }
        babyshark();
        System.out.println(result);
    }
}