import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] poleA = new int[n + 1];
        int[] arr = new int[500001];
        int[] idxArr = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            poleA[i] = Integer.parseInt(st.nextToken());
            arr[poleA[i]] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(poleA);
        ArrayList<Integer> list = new ArrayList<>();
        list.add(Integer.MIN_VALUE);
        for (int i = 1; i <= n; i++) {
            if (arr[poleA[i]] > list.get(list.size() - 1)) {
                idxArr[i] = list.size();
                list.add(arr[poleA[i]]);
            } else {
                int left = 1, right = list.size() - 1, idx = 1;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (list.get(mid) >= arr[poleA[i]]) {
                        idx = mid;
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                list.set(idx, arr[poleA[i]]);
                idxArr[i] = idx;
            }
        }
        int max = list.size() - 1;
        StringBuilder sb = new StringBuilder();
        sb.append(n - max).append("\n");
        Stack<Integer> stack = new Stack<>();
        for (int i = n; i > 0; i--) {
            if (idxArr[i] == max) max--;
            else stack.push(poleA[i]);
        }
        while (!stack.isEmpty()) {
            sb.append(stack.pop()).append("\n");
        }
        System.out.print(sb);
    }
}