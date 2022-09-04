import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {    
    public static void initParent(int[] parent, int n) {
        for (int i = 0; i < n; i++) {
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
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] parent = new int[n];
        initParent(parent, n);
        int cnt = 0;
        boolean isFirst = true;
        for (int i = 1; i <= m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            if (!isUnion(parent, a, b)) {
                unionParent(parent, a, b);
            } else if (isFirst) {
                isFirst = false;
                cnt = i;
            }
        }
        System.out.println(cnt);
    }
}