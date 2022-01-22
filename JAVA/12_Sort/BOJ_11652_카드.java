import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        HashMap<Long, Integer> map = new HashMap<Long, Integer>();
        int max = 1;
        long result = 0;
        boolean first = true;
        for (int i = 0; i < n; i++) {
            long key = Long.parseLong(br.readLine());
            if (!map.containsKey(key)) {
                map.put(key, 1);
                if (first) {
                    result = key;
                    first = false;
                } else if (max == 1) {
                    result = Math.min(result, key);
                }
            } else {
                map.put(key, map.get(key) + 1);
                if (max == map.get(key)) {
                    result = Math.min(result, key);
                } else if (map.get(key) > max) {
                    max = map.get(key);
                    result = key;
                }
            }
        }
        System.out.println(result);
    }
}