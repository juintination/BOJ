import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.HashSet;

public class Main {

    public static void initParent(int[] parent, int n) {
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    public static int findParent(int[] parent, int x) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent, parent[x]);
    }

    public static void unionParent(int[] parent, int a, int b) {
        a = findParent(parent, a);
        b = findParent(parent, b);
        if (a == b) {
            parent[a] = 0;
        } else if (a < b) {
            parent[b] = a;
        } else parent[a] = b;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        for (int cnt = 1; true; cnt++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            if (n == 0 && m == 0) break;
            int[] parent = new int[n + 1];
            initParent(parent, n);
            while (m-- > 0) {
                st = new StringTokenizer(br.readLine(), " ");
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                unionParent(parent, a, b);
            }
            HashSet<Integer> set = new HashSet<>();
            for (int i = 1; i <= n; i++) {
                int pi = findParent(parent, i);
                if (pi > 0) set.add(pi);
            }
            sb.append("Case ").append(cnt).append(": ");
            if (set.isEmpty()) {
                sb.append("No trees.\n");
            } else if (set.size() == 1) {
                sb.append("There is one tree.\n");
            } else {
                sb.append("A forest of ").append(set.size()).append(" trees.\n");
            }
        }
        System.out.print(sb);
    }
}