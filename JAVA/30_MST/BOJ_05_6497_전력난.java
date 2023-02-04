import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class node implements Comparable<node> {
    int from, to, cost;

    public node(int from, int to, int cost) {
        this.from = from;
        this.to = to;
        this.cost = cost;
    }

    @Override
    public int compareTo(node o) {
        return cost - o.cost;
    }
}

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
        StringBuilder sb = new StringBuilder();
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int m = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());
            if (m == 0 && n == 0) break;
            int[] parent = new int[m];
            initParent(parent, m);
            PriorityQueue<node> pqueue = new PriorityQueue<>();
            int sum = 0;
            while (n-- > 0) {
                st = new StringTokenizer(br.readLine(), " ");
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                int c = Integer.parseInt(st.nextToken());
                pqueue.offer(new node(a, b, c));
                sum += c;
            }
            while (!pqueue.isEmpty()) {
                node p = pqueue.poll();
                if (!isUnion(parent, p.from, p.to)) {
                    unionParent(parent, p.from, p.to);
                    sum -= p.cost;
                }
            }
            sb.append(sum).append("\n");
        }
        System.out.print(sb);
    }
}