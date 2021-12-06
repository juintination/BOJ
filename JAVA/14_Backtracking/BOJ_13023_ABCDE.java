import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    static int n, m;
    static boolean[] visited;
    static ArrayList<Integer>[] list;

    public static void dfs(int dpth, int idx) {
        if (dpth == 4) {
            System.out.println(1);
            System.exit(0);
        }
        visited[idx] = true;
        if (list[idx] != null) {
            for (int e : list[idx]) {
                if (!visited[e]) {
                    dfs(dpth + 1, e);
                }
            }
        }
        visited[idx] = false;
    }

    @SuppressWarnings("unchecked")
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        visited = new boolean[n];
        list = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            list[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            list[x].add(y);
            list[y].add(x);
        }
        for (int i = 0; i < n; i++) {
            dfs(0, i);
        }
        System.out.println(0);
    }
}