import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int c = Integer.parseInt(st.nextToken());
        int p = Integer.parseInt(st.nextToken());
        int[] arr = new int[c];
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < c; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        int cnt = 0;
        if (p == 1) {
            cnt = c;
            for (int i = 0; i < c - 3; i++) {
                if (arr[i] == arr[i + 1] && arr[i] == arr[i + 2] && arr[i] == arr[i + 3]) {
                    cnt++;
                }
            }
        } else if (p == 2) {
            for (int i = 0; i < c - 1; i++) {
                if (arr[i] == arr[i + 1]) {
                    cnt++;
                }
            }
        } else if (p == 3) {
            for (int i = 0; i < c - 2; i++) {
                if (arr[i] == arr[i + 1] && arr[i] == arr[i + 2] - 1) {
                    cnt++;
                }
            }
            for (int i = 0; i < c - 1; i++) {
                if (arr[i] == arr[i + 1] + 1) {
                    cnt++;
                }
            }
        } else if (p == 4) {
            for (int i = 0; i < c - 2; i++) {
                if (arr[i] == arr[i + 1] + 1 && arr[i] == arr[i + 2] + 1) {
                    cnt++;
                }
            }
            for (int i = 0; i < c - 1; i++) {
                if (arr[i] == arr[i + 1] - 1) {
                    cnt++;
                }
            }
        } else if (p == 5) {
            for (int i = 0; i < c - 2; i++) {
                if (arr[i] == arr[i + 1] && arr[i] == arr[i + 2]) {
                    cnt++;
                } else if (arr[i] == arr[i + 1] + 1 && arr[i] == arr[i + 2]) {
                    cnt++;
                }
            }
            for (int i = 0; i < c - 1; i++) {
                if (arr[i] == arr[i + 1] + 1) {
                    cnt++;
                } else if (arr[i] == arr[i + 1] - 1) {
                    cnt++;
                }
            }
        } else if (p == 6) {
            for (int i = 0; i < c - 2; i++) {
                if (arr[i] == arr[i + 1] && arr[i] == arr[i + 2]) {
                    cnt++;
                } else if (arr[i] == arr[i + 1] - 1 && arr[i] == arr[i + 2] - 1) {
                    cnt++;
                }
            }
            for (int i = 0; i < c - 1; i++) {
                if (arr[i] == arr[i + 1]) {
                    cnt++;
                } else if (arr[i] == arr[i + 1] + 2) {
                    cnt++;
                }
            }
        } else if (p == 7) {
            for (int i = 0; i < c - 2; i++) {
                if (arr[i] == arr[i + 1] && arr[i] == arr[i + 2]) {
                    cnt++;
                } else if (arr[i] == arr[i + 1] && arr[i] == arr[i + 2] + 1) {
                    cnt++;
                }
            }
            for (int i = 0; i < c - 1; i++) {
                if (arr[i] == arr[i + 1]) {
                    cnt++;
                } else if (arr[i] == arr[i + 1] - 2) {
                    cnt++;
                }
            }
        }
        System.out.println(cnt);
    }
}