import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        double x = Double.parseDouble(st.nextToken());
        double y = Double.parseDouble(st.nextToken());
        double c = Double.parseDouble(st.nextToken());
        double min = 0, max = Math.min(x, y);
        while (min <= max) {
            double mid = (max + min) / 2;
            double a = mid * c / Math.sqrt(Math.pow(x, 2) - Math.pow(mid, 2));
            double b = mid * c / Math.sqrt(Math.pow(y, 2) - Math.pow(mid, 2));
            if (Math.abs(mid - (a + b)) < 0.001) {
                System.out.printf("%.3f", mid);
                break;
            }
            if (mid > a + b) {
                min = mid;
            } else {
                max = mid;
            }
        }
    }
}