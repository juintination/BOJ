import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n + 1];
        int[] idxArr = new int[n + 1];
        ArrayList<Integer> list = new ArrayList<>();
        list.add(Integer.MIN_VALUE);
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 1; i <= n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            if (arr[i] > list.get(list.size() - 1)) {
                idxArr[i] = list.size();
                list.add(arr[i]);
            } else {
                int left = 1, right = list.size() - 1, idx = 1;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (list.get(mid) >= arr[i]) {
                        idx = mid;
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                list.set(idx, arr[i]);
                idxArr[i] = idx;
            }
        }
        int max = list.size() - 1;
        StringBuilder sb = new StringBuilder();
        sb.append(max).append("\n");
        Stack<Integer> stack = new Stack<>();
        while (max > 0) {
            if (idxArr[n] == max) {
                stack.push(arr[n--]);
                max--;
            } else n--;
        }
        while (!stack.isEmpty()) {
            sb.append(stack.pop()).append(" ");
        }
        System.out.println(sb);
    }
}