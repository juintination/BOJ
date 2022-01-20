import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Comparator;
import java.util.StringTokenizer;

class point implements Comparable<point> {
    int m, v;

    public point(int m, int v) {
        this.m = m;
        this.v = v;
    }

    @Override
    public int compareTo(point o) {
        return m - o.m;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        point[] arr = new point[n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int m = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            arr[i] = new point(m, v);
        }
        Arrays.sort(arr);
        int[] c = new int[k];
        for (int i = 0; i < k; i++) {
            c[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(c);
        PriorityQueue<Integer> queue = new PriorityQueue<>(Comparator.reverseOrder());

        long sum = 0;
        int idx = 0;
        for (int i = 0; i < k; i++) {
            while (idx < n && arr[idx].m <= c[i]) {
                queue.offer(arr[idx++].v);
            }
            if (!queue.isEmpty()) {
                sum += queue.poll();
            }
        }
        System.out.println(sum);
    }
}