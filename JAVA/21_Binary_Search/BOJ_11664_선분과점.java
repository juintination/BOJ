import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        double ax = Double.parseDouble(st.nextToken());
        double ay = Double.parseDouble(st.nextToken());
        double az = Double.parseDouble(st.nextToken());
        double bx = Double.parseDouble(st.nextToken());
        double by = Double.parseDouble(st.nextToken());
        double bz = Double.parseDouble(st.nextToken());
        double cx = Double.parseDouble(st.nextToken());
        double cy = Double.parseDouble(st.nextToken());
        double cz = Double.parseDouble(st.nextToken());
        double lx = ax, ly = ay, lz = az;
        double rx = bx, ry = by, rz = bz;
        double min = Integer.MAX_VALUE;
        while (true) {
            double mx = (lx + rx) / 2, my = (ly + ry) / 2, mz = (lz + rz) / 2;
            double md = Math.sqrt(Math.pow(mx - cx, 2) + Math.pow(my - cy, 2) + Math.pow(mz - cz, 2));
            if (Math.abs(md - min) <= 0.000001) {
                System.out.printf("%.10f", min);
                break;
            }
            min = Math.min(min, md);
            double ld = Math.sqrt(Math.pow(lx - cx, 2) + Math.pow(ly - cy, 2) + Math.pow(lz - cz, 2));
            double rd = Math.sqrt(Math.pow(rx - cx, 2) + Math.pow(ry - cy, 2) + Math.pow(rz - cz, 2));
            if (rd < ld) {
                lx = mx;
                ly = my;
                lz = mz;
            } else {
                rx = mx;
                ry = my;
                rz = mz;
            }
        }
    }
}