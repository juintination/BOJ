import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void mergeSort(int A[], int low, int high, int B[]) {
        if (low >= high) return;
        int mid = (low + high) / 2;
        mergeSort(A, low, mid, B);
        mergeSort(A, mid + 1, high, B);
        int i = low, j = mid + 1;
        for (int k = low; k <= high; k++) {
            if (j > high) B[k] = A[i++];
            else if (i > mid) B[k] = A[j++];
            else if (A[i] <= A[j]) B[k] = A[i++];
            else B[k] = A[j++];
        }
        for (i = low; i <= high; i++) A[i] = B[i];
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(br.readLine());
        }
        int[] b = new int[n];
        mergeSort(a, 0, n - 1, b);
        for (int i = 0; i < n; i++) {
            sb.append(a[i]).append('\n');
        }
        System.out.println(sb);
    }
}