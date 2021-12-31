import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] alph = new int[26];
		for (int i = 0; i < n; i++) {
			char[] arr = br.readLine().toCharArray();
			int pos = (int) Math.pow(10, arr.length - 1);
			for (int j = 0; j < arr.length; j++) {
				alph[arr[j] - 'A'] += pos;
				pos /= 10;
			}
		}
		Arrays.sort(alph);
		int sum = 0;
		for (int i = 1; i <= 10; i++) {
			sum += alph[26 - i] * (10 - i);
		}
		System.out.println(sum);
	}
}