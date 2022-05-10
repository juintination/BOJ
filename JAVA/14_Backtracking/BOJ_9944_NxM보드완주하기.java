import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, m, min, board;
    static char[][] arr;
    static boolean[][] visited;
    static int[] dx = { -1, 0, 1, 0 };
    static int[] dy = { 0, -1, 0, 1 };

    public static void dfs(int dpth, int x, int y, int moved) {
        if (moved == board) {
            min = Math.min(min, dpth);
            return;
        }
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x, ny = y;
            while (true) {
                nx += dx[i];
                ny += dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] != '*' && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    cnt++;
                } else break;
            }
            if (cnt == 0) continue;
            nx -= dx[i];
            ny -= dy[i];
            dfs(dpth + 1, nx, ny, moved + cnt);
            while (cnt > 0) {
                visited[nx][ny] = false;
                nx -= dx[i];
                ny -= dy[i];
                cnt--;
            }
        }
    }

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input;
        int cnt = 1;
        StringBuilder sb = new StringBuilder();
        while ((input = br.readLine()) != null) {
            StringTokenizer st = new StringTokenizer(input, " ");
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            arr = new char[n][m];
            visited = new boolean[n][m];
            min = Integer.MAX_VALUE;
            board = 0;
            for (int i = 0; i < n; i++) {
                String str = br.readLine();
                for (int j = 0; j < m; j++) {
                    arr[i][j] = str.charAt(j);
                    if (arr[i][j] == '.') {
                        board++;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (arr[i][j] == '.') {
                        visited[i][j] = true;
                        dfs(0, i, j, 1);
                        visited[i][j] = false;
                    }
                }
            }
            if (min == Integer.MAX_VALUE) {
                sb.append("Case ").append(cnt++).append(": ").append(-1).append("\n");
            } else {
                sb.append("Case ").append(cnt++).append(": ").append(min).append("\n");
            }
        }
        System.out.print(sb);
    }
}