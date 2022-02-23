import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

class point {
    int x, y, s;

    public point(int x, int y, int s) {
        this.x = x;
        this.y = y;
        this.s = s;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        char[][] arr = new char[n][m];
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = str.charAt(j);
            }
        }
        boolean[][] visited = new boolean[n][m];
        ArrayList<point> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int size = 0;
                if (arr[i][j] == '*') {
                    int k = 1;
                    while (true) {
                        if (i - k >= 0 && i + k < n && j - k >= 0 && j + k < m) {
                            if (arr[i - k][j] == '*' && arr[i + k][j] == '*' && arr[i][j - k] == '*' && arr[i][j + k] == '*') {
                                size = k++;
                            } else break;
                        } else break;
                    }
                }
                if (size > 0) {
                    list.add(new point(i + 1, j + 1, size));
                    visited[i][j] = true;
                    for (int k = 1; k <= size; k++) {
                        visited[i - k][j] = visited[i + k][j] = visited[i][j - k] = visited[i][j + k] = true;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == '*' && !visited[i][j]) {
                    System.out.println(-1);
                    System.exit(0);
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        int sum = 0;
        for (point e : list) {
            sum += e.s;
        }
        sb.append(sum).append("\n");
        for (int i = 0; i < list.size(); i++) {
            point p = list.get(i);
            for (int j = p.s; j >= 1; j--) {
                sb.append(p.x).append(" ").append(p.y).append(" ").append(j).append("\n");
            }
        }
        System.out.print(sb);
    }
}