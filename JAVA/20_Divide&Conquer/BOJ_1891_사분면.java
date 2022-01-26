import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int d;
    static long tx, ty;
    static String str;
    static StringBuilder sb = new StringBuilder();

    public static void quadTree(long tx, long ty, long size) {
        if (size == 1) {
            System.out.println(sb);
            System.exit(0);
        }
        size /= 2;
        if (tx < size && ty >= size) {
            sb.append(1);
            quadTree(tx, ty - size, size);
        } else if (tx < size && ty < size) {
            sb.append(2);
            quadTree(tx, ty, size);
        } else if (tx >= size && ty < size) {
            sb.append(3);
            quadTree(tx - size, ty, size);
        } else if (tx >= size && ty >= size) {
            sb.append(4);
            quadTree(tx - size, ty - size, size);
        }
    }

    public static void targeted(long x, long y, long size, int idx) {
        if (idx == d) {
            tx = x;
            ty = y;
            return;
        }
        size /= 2;
        if (str.charAt(idx) == '1') {
            targeted(x, y + size, size, idx + 1);
        } else if (str.charAt(idx) == '2') {
            targeted(x, y, size, idx + 1);
        } else if (str.charAt(idx) == '3') {
            targeted(x + size, y, size, idx + 1);
        } else if (str.charAt(idx) == '4') {
            targeted(x + size, y + size, size, idx + 1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        d = Integer.parseInt(st.nextToken());
        str = st.nextToken();
        long size = (long) Math.pow(2, d);
        targeted(0, 0, size, 0);
        st = new StringTokenizer(br.readLine(), " ");
        long y = Long.parseLong(st.nextToken());
        long x = Long.parseLong(st.nextToken());
        tx -= x;
        ty += y;
        if (tx >= 0 && tx < size && ty >= 0 && ty < size) {
            quadTree(tx, ty, size);
        } else {
            System.out.println(-1);
        }
    }
}