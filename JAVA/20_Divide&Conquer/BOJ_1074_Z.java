import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int cnt = 0;

    public static void quadTree(int r, int c, int size) {
        if (size == 1) {
            System.out.println(cnt);
            System.exit(0);
        }
        size /= 2;
        if (r < size && c < size) {
            quadTree(r, c, size);
        } else if (r < size && c >= size) {
            cnt += Math.pow(size, 2);
            quadTree(r, c - size, size);
        } else if (r >= size && c < size) {
            cnt += Math.pow(size, 2) * 2;
            quadTree(r - size, c, size);
        } else if (r >= size && c >= size) {
            cnt += Math.pow(size, 2) * 3;
            quadTree(r - size, c - size, size);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int size = (int) Math.pow(2, n);
        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        quadTree(r, c, size);
    }
}