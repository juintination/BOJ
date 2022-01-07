import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;

class point {
    int x, y;

    public point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {

    static char[][] arr;
    static boolean[][] visited;

    public static void down() {
        for (int i = 7; i >= 0; i--) {
            for (int j = 7; j >= 0; j--) {
                if (i == 0) {
                    arr[i][j] = '.';
                } else {
                    arr[i][j] = arr[i - 1][j];
                }
            }
        }
    }

    public static void bfs() {
        Queue<point> queue = new LinkedList<>();
        queue.offer(new point(7, 0));
        int[] dx = { -1, 0, 1, 0, 0, -1, 1, -1, 1 };
        int[] dy = { 0, -1, 0, 1, 0, -1, -1, 1, 1 };
        while (!queue.isEmpty()) {
            int size = queue.size();
            visited = new boolean[8][8];
            for (int i = 0; i < size; i++) {
                point p = queue.poll();
                if (arr[p.x][p.y] == '#') continue;
                if (p.x == 0) {
                    System.out.println(1);
                    System.exit(0);
                }
                for (int j = 0; j < 9; j++) {
                    int nx = p.x + dx[j];
                    int ny = p.y + dy[j];
                    if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && !visited[nx][ny] && arr[nx][ny] == '.') {
                        queue.offer(new point(nx, ny));
                        visited[nx][ny] = true;
                    }
                }
            }
            down();
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        arr = new char[8][8];
        for (int i = 0; i < 8; i++) {
            String str = br.readLine();
            for (int j = 0; j < 8; j++) {
                arr[i][j] = str.charAt(j);
            }
        }
        bfs();
        System.out.println(0);
    }
}