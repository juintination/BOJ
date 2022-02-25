import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

class point {
    int r, c, area;

    point(int r, int c) {
        this.r = r;
        this.c = c;
        this.area = r * c;
    }
}

public class Main {

    static int h, w, n;
    static ArrayList<point> list;

    public static boolean paste(int r1, int c1, int r2, int c2) {
        if (r1 + r2 <= h && Math.max(c1, c2) <= w) return true;
        if (Math.max(r1, r2) <= h && c1 + c2 <= w) return true;
        return false;
    }

    public static boolean sticker(int r1, int c1, int r2, int c2) {
        if (paste(r1, c1, r2, c2)) return true;
        if (paste(c1, r1, r2, c2)) return true;
        if (paste(r1, c1, c2, r2)) return true;
        if (paste(c1, r1, c2, r2)) return true;
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        h = Integer.parseInt(st.nextToken());
        w = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(br.readLine());
        list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            if (r > h && r > w) continue;
            if (c > h && c > w) continue;
            list.add(new point(r, c));
        }
        int max = 0;
        for (int i = 0; i < list.size() - 1; i++) {
            for (int j = i + 1; j < list.size(); j++) {
                int r1 = list.get(i).r, c1 = list.get(i).c;
                int r2 = list.get(j).r, c2 = list.get(j).c;
                if (sticker(r1, c1, r2, c2)) {
                    max = Math.max(max, list.get(i).area + list.get(j).area);
                }
            }
        }
        System.out.println(max);
    }
}