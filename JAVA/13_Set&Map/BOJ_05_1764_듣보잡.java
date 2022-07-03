import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        HashSet<String> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            String hear = br.readLine();
            set.add(hear);
        }
        ArrayList<String> list = new ArrayList<>();
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            String see = br.readLine();
            if (set.contains(see)) {
                list.add(see);
                cnt++;
            }
        }
        StringBuilder sb = new StringBuilder();
        sb.append(cnt).append("\n");
        Collections.sort(list);
        for (String hear_see : list) {
            sb.append(hear_see).append("\n");
        }
        System.out.print(sb);
    }
}