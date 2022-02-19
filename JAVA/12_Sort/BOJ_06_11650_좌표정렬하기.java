import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

class point implements Comparable<point> {
    int x, y;

    public point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public int compareTo(point o) {
        if (this.x == o.x) {
            return this.y - o.y;
        } else {
            return this.x - o.x;
        }
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<point> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            list.add(new point(x, y));
        }
        Collections.sort(list);
        StringBuilder sb = new StringBuilder();
        for (point p : list) {
            sb.append(p.x).append(" ").append(p.y).append("\n");
        }
        System.out.print(sb);
    }
}