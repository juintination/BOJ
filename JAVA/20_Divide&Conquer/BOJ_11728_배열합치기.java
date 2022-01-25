import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] a = new int[n];
        int[] b = new int[m];
        int[] arr = new int[n + m];
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < m; i++) {
            b[i] = Integer.parseInt(st.nextToken());
        }
        int i = 0, j = 0, cnt = 0;
        while (i < n && j < m) {
            if (a[i] < b[j]) {
                arr[cnt++] = a[i++];
            } else {
                arr[cnt++] = b[j++];
            }
        }
        while (i < n) arr[cnt++] = a[i++];
        while (j < m) arr[cnt++] = b[j++];
        StringBuilder sb = new StringBuilder();
        for (int e : arr) {
            sb.append(e).append(" ");
        }
        System.out.println(sb);
    }
}