import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n;
    static int[] arr;

    public static void swap(int a, int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    public static boolean nextPermutation() {
        int i = n - 1;
        while (true) {
            if (i == 0 || arr[i - 1] < arr[i]) break;
            i--;
        }
        if (i == 0) {
            System.out.println(-1);
            return false;
        }
        int j = n - 1;
        while (true) {
            if (arr[i - 1] < arr[j]) break;
            j--;
        }
        swap(i - 1, j);
        int k = n - 1;
        while (i < k) {
            swap(i, k);
            i++;
            k--;
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        if (nextPermutation()) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) {
                sb.append(arr[i]).append(" ");
            }
            System.out.print(sb);
        }
    }
}