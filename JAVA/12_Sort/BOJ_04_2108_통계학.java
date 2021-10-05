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
        int a[] = new int[n];
        int[] cnt = new int[8001];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(br.readLine());
            a[i] += 4000;
            cnt[a[i]]++;
            sum += a[i] - 4000;
        }
        int b[] = new int[n];
        mergeSort(a, 0, n - 1, b);
        int cntmax = 0, frequent = 0, max = 0, min = 8000;
        for (int i = 0; i < n; i++) {
            cntmax = Math.max(cntmax, cnt[a[i]]);
            max = Math.max(max, a[i]);
            min = Math.min(min, a[i]);
        }
        for (int i = 0; i < n; i++) {
            if (cnt[a[i]] == cntmax) {
                frequent = i;
                break;
            }
        }
        for (int i = frequent + 1; i < n; i++) {
            if (cnt[a[i]] == cntmax && a[i] != a[frequent]) {
                frequent = i;
                break;
            }
        }
        sb.append((int)Math.round((double)sum / n)).append('\n');
        sb.append(a[n / 2] - 4000).append('\n');
        sb.append(a[frequent] - 4000).append('\n');
        sb.append(max - min).append('\n');
        System.out.print(sb);
    }
}