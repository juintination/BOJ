import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int[] arr1 = new int[n];
        int[] arr2 = new int[n];
        int[] bulb = new int[n];
        String now = br.readLine();
        String goal = br.readLine();
        for (int i = 0; i < n; i++) {
            arr1[i] = arr2[i] = now.charAt(i) - '0';
            bulb[i] = goal.charAt(i) - '0';
        }
        int cnt1 = 0, cnt2 = 1;
        for (int i = 0; i <= 1; i++) {
            arr2[i] = 1 - arr2[i];
        }
        for (int i = 1; i < n; i++) {
            if (arr1[i - 1] != bulb[i - 1]) {
                arr1[i - 1] = 1 - arr1[i - 1];
                arr1[i] = 1 - arr1[i];
                cnt1++;
                if (i != n - 1) {
                    arr1[i + 1] = 1 - arr1[i + 1];
                }
            }
            if (arr2[i - 1] != bulb[i - 1]) {
                arr2[i - 1] = 1 - arr2[i - 1];
                arr2[i] = 1 - arr2[i];
                cnt2++;
                if (i != n - 1) {
                    arr2[i + 1] = 1 - arr2[i + 1];
                }
            }
        }
        int INF = Integer.MAX_VALUE;
        if (arr1[n - 1] != bulb[n - 1]) cnt1 = INF;
        if (arr2[n - 1] != bulb[n - 1]) cnt2 = INF;
        if (cnt1 == INF && cnt2 == INF) {
            System.out.println(-1);
        } else {
            System.out.println(Math.min(cnt1, cnt2));
        }
    }
}