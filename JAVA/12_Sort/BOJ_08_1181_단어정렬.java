import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void mergeSort(String A[], int low, int high, String B[]) {
        if (low >= high) return;
        int mid = (low + high) / 2;
        mergeSort(A, low, mid, B);
        mergeSort(A, mid + 1, high, B);
        int i = low, j = mid + 1;
        for (int k = low; k <= high; k++) {
            if (j > high) B[k] = A[i++];
            else if (i > mid) B[k] = A[j++];
            else if (A[i].length() < A[j].length()) B[k] = A[i++];
            else if (A[i].length() == A[j].length()) { //문자열의 길이가 같을 때
                if (A[i].charAt(0) < A[j].charAt(0)) B[k] = A[i++]; //맨 앞글자가 i가 더 작을 때
                else if (A[i].charAt(0) > A[j].charAt(0)) B[k] = A[j++]; //맨 앞글자가 j가 더 작을 때
                else if (A[i].charAt(0) == A[j].charAt(0)) { //i와 j의 맨 앞글자가 같을 때
                    for (int z = 0; z < A[i].length(); z++) { //뒤의 글자를 비교하기 위한 for문
                        if (A[i].charAt(z) < A[j].charAt(z)) {
                            B[k] = A[i++];
                            break;
                        }
                        else if (A[i].charAt(z) > A[j].charAt(z)) {
                            B[k] = A[j++];
                            break;
                        }
                        else if (z == A[i].length() - 1) { //글자가 같은 경우(끝까지 비교했지만 다 같은 경우)
                            B[k] = A[i++];
                            B[++k] = A[j++];
                            break;
                        }
                    }
                }
            }
            else B[k] = A[j++];
        }
        for (i = low; i <= high; i++) A[i] = B[i];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        String a[] = new String[n];
        String b[] = new String[n];
        for (int i = 0; i < n; i++) {
            a[i] = br.readLine();
        }
        mergeSort(a, 0, n - 1, b);
        sb.append(a[0]).append('\n');
		for (int i = 1; i < n; i++) {
			// 중복되지 않는 단어만 출력
			if (!a[i].equals(a[i - 1])) {
				sb.append(a[i]).append('\n');
			}
		}
        System.out.print(sb);
    }
}