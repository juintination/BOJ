import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        long[] arr = new long[n - 1];
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        for (int i = 0; i < n - 1; i++) {
            arr[i] = Long.parseLong(st.nextToken());
        }
        long[] cost = new long[n];
        st = new StringTokenizer(br.readLine()," ");
        for (int i = 0; i < n; i++) {
            cost[i] = Long.parseLong(st.nextToken());
        }
        long min = cost[0], sum = 0;
        for (int i = 0; i < n - 1; i++) {
            min = Math.min(min, cost[i]);
            sum += min * arr[i];
        }
        System.out.println(sum);
    }
}