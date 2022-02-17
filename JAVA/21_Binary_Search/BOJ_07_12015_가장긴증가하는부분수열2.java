import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<Integer> list = new ArrayList<>();
        list.add(0);
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; i++) {
            int value = Integer.parseInt(st.nextToken());
            if (value > list.get(list.size() - 1)) {
                list.add(value);
            } else {
                int left = 0, right = list.size() - 1, idx = 0;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (list.get(mid) >= value) {
                        idx = mid;
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                list.set(idx, value);
            }
        }
        System.out.println(list.size() - 1);
    }
}