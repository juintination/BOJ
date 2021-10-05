import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        double arr[] = new double[n];
        double max = 0, avg = 0;
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            if (arr[i] > max)  max = arr[i];
        }
        for (int i = 0; i < n; i++) {
            arr[i] *= (100 / max);
            avg += arr[i];
        }
        avg /= n;
        System.out.println(avg);
    }
}