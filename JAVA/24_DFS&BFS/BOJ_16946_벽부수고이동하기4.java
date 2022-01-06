import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;

class point {
    int x;
    int y;

    public point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {

    static int n, m;
    static int[][] arr, district;
    static HashMap<Integer, Integer> map;
    static int[] dy = { -1, 0, 1, 0 };
    static int[] dx = { 0, -1, 0, 1 };

    public static void bfs(int x, int y, int idx) {
        Queue<point> queue = new LinkedList<>();
        queue.offer(new point(x, y));
        district[x][y] = idx;
        int cnt = 0;
        while (!queue.isEmpty()) {
            point p = queue.poll();
            cnt++;
            for (int i = 0; i < 4; i++) {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] == 0) {
                    if (district[nx][ny] == 0) {
                        district[nx][ny] = idx;
                        queue.offer(new point(nx, ny));
                    }
                }
            }
        }
        map.put(idx, cnt);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n][m];
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = str.charAt(j) - '0';
            }
        }
        district = new int[n][m];
        map = new HashMap<>();
        int idx = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 0 && district[i][j] == 0) {
                    bfs(i, j, idx++);
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 1) {
                    HashSet<Integer> used = new HashSet<>();
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] == 0) {
                            int d = district[nx][ny];
                            if (!used.contains(d)) {
                                used.add(d);
                                arr[i][j] += map.get(d);
                            }
                        }
                    }
                    sb.append(arr[i][j] % 10);
                } else if (arr[i][j] == 0) {
                    sb.append(0);
                }
            }
            sb.append("\n");
        }
        System.out.print(sb);
    }
}