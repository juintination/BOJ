import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class point {
    double x, y;

    public point(double x, double y) {
        this.x = x;
        this.y = y;
    }
}

class node implements Comparable<node> {
    int from, to;
    double cost;

    public node(int from, int to, double cost) {
        this.from = from;
        this.to = to;
        this.cost = cost;
    }

    @Override
    public int compareTo(node o) {
        if (cost > o.cost)
            return 1;
        else if (cost < o.cost)
            return -1;
        else
            return 0;
    }
}

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
    
    public static double distance(point o1, point o2) {
        return Math.sqrt(Math.pow(o1.x - o2.x, 2) + Math.pow(o1.y - o2.y, 2));
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] parent = new int[n + 1];
        initParent(parent, n);
        point[] arr = new point[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            double x = Double.parseDouble(st.nextToken());
            double y = Double.parseDouble(st.nextToken());
            arr[i] = new point(x, y);
        }
        PriorityQueue<node> pqueue = new PriorityQueue<>();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                double d = distance(arr[i], arr[j]);
                pqueue.offer(new node(i, j, d));
            }
        }
        double sum = 0;
        while (!pqueue.isEmpty()) {
            node p = pqueue.poll();
            if (!isUnion(parent, p.from, p.to)) {
                unionParent(parent, p.from, p.to);
                sum += p.cost;
            }
        }
        System.out.println(String.format("%.2f", sum));
    }
}