import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;
import java.util.HashSet;
import java.util.StringTokenizer;

class point {
    long s;
    String str;

    public point(long s, String str) {
        this.s = s;
        this.str = str;
    }
}

public class Main {

    static long s, t;
    static HashSet<Long> set;

    public static void bfs() {
        Queue<point> queue = new LinkedList<>();
        queue.offer(new point(s, ""));
        set.add(s);
        while (!queue.isEmpty()) {
            point p = queue.poll();
            if (p.s == t) {
                System.out.println(p.str);
                System.exit(0);
            }
            if (p.s <= Math.sqrt(t) && !set.contains(p.s * p.s)) {
                set.add(p.s * p.s);
                queue.offer(new point(p.s * p.s, p.str + '*'));
            }
            if (p.s <= t / 2 && !set.contains(p.s + p.s)) {
                set.add(p.s + p.s);
                queue.offer(new point(p.s + p.s, p.str + '+'));
            }
            if (p.s > t && !set.contains(p.s - p.s)) {
                set.add(p.s - p.s);
                queue.offer(new point(p.s - p.s, p.str + '-'));
            }
            if (p.s != 0 && !set.contains(p.s / p.s)) {
                set.add(p.s / p.s);
                queue.offer(new point(p.s / p.s, p.str + '/'));
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        s = Long.parseLong(st.nextToken());
        t = Long.parseLong(st.nextToken());
        set = new HashSet<>();
        if (s == t) {
            System.out.println(0);
            System.exit(0);
        } else bfs();
        System.out.println(-1);
    }
}