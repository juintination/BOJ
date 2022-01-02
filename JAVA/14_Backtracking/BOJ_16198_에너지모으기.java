import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

	static int n, max = 0;

	public static void dfs(int dpth, ArrayList<Integer> list, int sum) {
		if (dpth == n - 2) {
			max = Math.max(max, sum);
			return;
		}
		for (int i = 1; i < list.size() - 1; i++) {
			int energy = list.get(i - 1) * list.get(i + 1);
			int tmp = list.get(i);
			list.remove(i);
			dfs(dpth + 1, list, sum + energy);
			list.add(i, tmp);
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		ArrayList<Integer> list = new ArrayList<>();
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		for (int i = 0; i < n; i++) {
			list.add(Integer.parseInt(st.nextToken()));
		}
		dfs(0, list, 0);
		System.out.println(max);
	}
}