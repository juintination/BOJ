import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {
    public static void quickSort(int arr[], int left, int right) {
        int i = left, j = right, pivot = arr[(left + right) / 2], temp;
        do {
            while (arr[i] < pivot) i++;
            while (arr[j] > pivot) j--;
            if (i <= j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        } while (i <= j);
        if (left < j) quickSort(arr, left, j);
        if (i < right) quickSort(arr, i, right);
    }

    public static void main(String[] args) throws IOException {
        HashMap<Integer, Integer> hmap = new HashMap<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int num[] = new int[n];
        int shortnum[] = new int[n];
        String str = br.readLine();
        String[] temp = str.split(" ");
        for (int i = 0; i < n; i++) {
            num[i] = Integer.parseInt(temp[i]);
            shortnum[i] = num[i];
        }
        quickSort(shortnum, 0, n - 1);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (hmap.get(shortnum[i]) == null) {
                hmap.put(shortnum[i], cnt++);
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            sb.append(hmap.get(num[i])).append(" ");
        }
        System.out.println(sb.toString());
    }
}