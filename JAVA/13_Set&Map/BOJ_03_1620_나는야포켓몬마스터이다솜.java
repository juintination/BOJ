import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        HashMap<String, String> map = new HashMap<>();
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= n; i++) {
            String poke = br.readLine();
            map.put(poke, Integer.toString(i));
            map.put(Integer.toString(i), poke);
        }
        StringBuilder sb = new StringBuilder();
        while (m-- > 0) {
            sb.append(map.get(br.readLine())).append("\n");
        }
        System.out.print(sb);
    }
}