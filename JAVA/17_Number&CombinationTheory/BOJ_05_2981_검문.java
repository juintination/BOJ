import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Collections;

public class Main {

    public static int gcd(int a, int b){
        while (b != 0){
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(arr);
        int d = arr[1] - arr[0];
        for (int i = 2; i < n; i++) {
            d = gcd(d, arr[i] - arr[i - 1]);
        }
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 2; i <= Math.sqrt(d); i++) {
            if (Math.pow(i, 2) == d) {
                list.add(i);
            } else if (d % i == 0) {
                list.add(i);
                list.add(d / i);
            }
        }
        list.add(d);
        Collections.sort(list);
        StringBuilder sb = new StringBuilder();
        for (int e : list) {
            sb.append(e).append(" ");
        }
        System.out.println(sb);
    }
}