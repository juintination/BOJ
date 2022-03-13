import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

class point {
    int x, y;

    public point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {

    static int n, m, result;
    static int[][] arr;
    static ArrayList<point> home, chicken;
    static boolean[] visited;

    public static void dfs(int dpth, int idx) {
        if (dpth == m) {
            int sum = 0;
            for (int i = 0; i < home.size(); i++) {
                int min = Integer.MAX_VALUE;
                for (int j = 0; j < chicken.size(); j++) {
                    if (visited[j]) {
                        int d = Math.abs(home.get(i).x - chicken.get(j).x) + Math.abs(home.get(i).y - chicken.get(j).y);
                        min = Math.min(min, d);
                    }
                }
                sum += min;
            }
            result = Math.min(result, sum);
            return;
        }
        for (int i = idx; i < chicken.size(); i++) {
            visited[i] = true;
            dfs(dpth + 1, i + 1);
            visited[i] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n][n];
        home = new ArrayList<>();
        chicken = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (arr[i][j] == 1) {
                    home.add(new point(i, j));
                } else if (arr[i][j] == 2) {
                    chicken.add(new point(i, j));
                }
            }
        }
        visited = new boolean[chicken.size()];
        result = Integer.MAX_VALUE;
        dfs(0, 0);
        System.out.println(result);
    }
}