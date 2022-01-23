import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

class point implements Comparable<point> {
    int num, idx;

    public point(int num, int idx) {
        this.num = num;
        this.idx = idx;
    }

    @Override
    public int compareTo(point o) {
        if (num == o.num) {
            return idx - o.idx;
        }
        return num - o.num;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        PriorityQueue<point> queue = new PriorityQueue<>();
        for (int i = 1; i <= n; i++) {
            queue.offer(new point(Integer.parseInt(br.readLine()), i));
        }
        int max = 0;
        for (int i = 0; i < n; i++) {
            max = Math.max(max, queue.poll().idx - i);
        }
        System.out.println(max);
    }
}