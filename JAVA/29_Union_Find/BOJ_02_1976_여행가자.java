import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

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
        if (a < b) parent[b] = a;
        else parent[a] = b;
    }

    public static boolean isUnion(int[] parent, int a, int b) {
        a = findParent(parent, a);
        b = findParent(parent, b);
        return (a == b);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        int[] parent = new int[n + 1];
        int[] root = new int[n + 1];
        initParent(parent, n);
        for (int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            for (int j = 1; j <= n; j++) {
                root[j] = Integer.parseInt(st.nextToken());
                if (root[j] == 1) {
                    unionParent(parent, i, j);
                }
            }
        }
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int pre = Integer.parseInt(st.nextToken());
        for (int i = 1; i < m; i++) {
            if (!isUnion(parent, pre, Integer.parseInt(st.nextToken()))) {
                System.out.println("NO");
                System.exit(0);
            }
        }
        System.out.println("YES");
    }
}