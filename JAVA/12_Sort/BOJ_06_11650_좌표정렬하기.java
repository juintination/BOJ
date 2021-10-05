import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void quickSort(int arrx[], int arry[], int left, int right) {
        int i = left, j = right, pivot = arrx[(left + right) / 2], temp;
        do {
            while (arrx[i] < pivot) i++;
            while (arrx[j] > pivot) j--;
            if (i <= j) {
                temp = arrx[i];
                arrx[i] = arrx[j];
                arrx[j] = temp;
                temp = arry[i];
                arry[i] = arry[j];
                arry[j] = temp;
                i++;
                j--;
            }
        } while (i <= j);
        if (left < j) quickSort(arrx, arry, left, j);
        if (i < right) quickSort(arrx, arry, i, right);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        int a[] = new int[n];
        int b[] = new int[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            a[i] = Integer.parseInt(st.nextToken());
            b[i] = Integer.parseInt(st.nextToken());
        }
        quickSort(a, b, 0, n - 1);
        while (true) {
            int cnt = 0, tmp;
            for (int i = 0; i < n - 1; i++) {
                if (a[i] == a[i + 1]) {
                    if (b[i] > b[i + 1]) {
                        tmp = b[i + 1];
                        b[i + 1] = b[i];
                        b[i] = tmp;
                        cnt++;
                    }
                }
            }
            if (cnt == 0) break;
        }
        for (int i = 0; i < n; i++) {
            sb.append(a[i]).append(" ").append(b[i]).append("\n");
        }
        System.out.print(sb);
    }
}