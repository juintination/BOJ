import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Arrays;
import java.util.HashMap;

public class Main {
    public static void initFriend(int[] friend, int n) {
        for (int i = 0; i < n; i++) {
            friend[i] = i;
        }
    }

    public static int findFriend(int[] friend, int x) {
        if (friend[x] == x) return x;
        return friend[x] = findFriend(friend, friend[x]);
    }
    
    public static int unionFriend(int[] friend, int[] cnt, int a, int b) {
        a = findFriend(friend, a);
        b = findFriend(friend, b);
        if (a < b) {
            friend[b] = a;
            cnt[a] += cnt[b];
            return cnt[a];
        } else if (a > b) {
            friend[a] = b;
            cnt[b] += cnt[a];
            return cnt[b];
        } else return cnt[a];
    }

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (t-- > 0) {
            HashMap<String, Integer> map = new HashMap<>();
            int f = Integer.parseInt(br.readLine());
            int[] friend = new int[f * 2];
            int[] cnt = new int[f * 2];
            initFriend(friend, f * 2);
            Arrays.fill(cnt, 1);
            int idx = 0;
            while (f-- > 0) {
                StringTokenizer st = new StringTokenizer(br.readLine(), " ");
                String a = st.nextToken();
                String b = st.nextToken();
                if (!map.containsKey(a)) {
                    map.put(a, idx++);
                }
                if (!map.containsKey(b)){
                    map.put(b, idx++);
                }
                sb.append(unionFriend(friend, cnt, map.get(a), map.get(b))).append("\n");
            }
        }
        System.out.print(sb);
	}
}